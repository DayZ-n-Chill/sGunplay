class AimingModelFilterInertia : AimingModelFilterBase {
	
	
	protected vector m_accel;
	protected vector m_vel;
	
	protected float m_currInertiaVelX[1];
	protected float m_currInertiaVelY[1];
	protected float m_currResetVelX[1];
	protected float m_currResetVelY[1];
	
	override bool isActive() {
		return GunplayConstants.AIMING_MODEL_USE_WEAPON_INERTIA;
	}
	
	override void onUpdate(float pDt, SDayZPlayerAimingModel pModel, int stanceIndex) {
		
		//////////////////////////
		// ACCELERATION
		m_accel = getAimingModel().getAimChangeDegree();
		m_vel += m_accel;
		m_vel[0] = Math.Clamp(m_vel[0], GunplayConstants.INERTIA_VELOCITY_LIMIT[1], GunplayConstants.INERTIA_VELOCITY_LIMIT[2]);
		m_vel[1] = Math.Clamp(m_vel[1], GunplayConstants.INERTIA_VELOCITY_LIMIT[3], GunplayConstants.INERTIA_VELOCITY_LIMIT[0]);
		
		float inertiaSpeedAcceleration[2];
		float inertiaSpeedReset[2];
		
		if (getPlayer().IsInOptics() || getPlayer().IsInIronsights()) {
			inertiaSpeedAcceleration = GunplayConstants.INERTIA_SPEED_ACCELERATION;
			inertiaSpeedReset = GunplayConstants.INERTIA_SPEED_RESET;
		} else {
			inertiaSpeedAcceleration = GunplayConstants.INERTIA_SPEED_ACCELERATION_HIPFIRE;
			inertiaSpeedReset = GunplayConstants.INERTIA_SPEED_RESET_HIPFIRE;
		}
		
		float multiplier = computeInertiaMultiplier();
		
		pModel.m_fAimXHandsOffset += Math.SmoothCD(
			0,
			m_vel[0] * multiplier,
			m_currInertiaVelX,
			inertiaSpeedAcceleration[0], 1000, pDt);
		
		pModel.m_fAimYHandsOffset += Math.SmoothCD(
			0,
			m_vel[1] * multiplier,
			m_currInertiaVelY,
			inertiaSpeedAcceleration[1], 1000, pDt);
		
				
		//////////////////////////
		// DECELERATION		
		m_vel[0] = Math.SmoothCD(
			m_vel[0],
			0,
			m_currResetVelX,
			inertiaSpeedReset[0], 1000, pDt);
		
		m_vel[1] = Math.SmoothCD(
			m_vel[1],
			0,
			m_currResetVelY,
			inertiaSpeedReset[1], 1000, pDt);
		
		if (GetGame().IsClient()) {
			pModel.m_fAimXCamOffset -= m_vel[0] * 0.01;
			pModel.m_fAimYCamOffset -= m_vel[1] * 0.01;
		}
		
		
	}
	
	/**
	*	@brief Compute the amount of inertia
	*	 @param weapon \p Weapon_Base - Weapon used for the computation
	*	 @return float - inertia amount
	*/
	protected float computeInertiaMultiplier() {
		//if (getPlayer().IsHoldingBreath()) return 0.9;
		float inertiaMultiplier = GunplayConstants.INERTIA_MULTIPLIER_BASE;

		////////////////////////
		// STANCE 
		inertiaMultiplier *= getInertiaMultiplierStance();
		
		////////////////////////
		// MOVEMENT
		inertiaMultiplier *= getInertiaMultiplierMovement();
		
		////////////////////////
		// WEAPON WEIGHT
		inertiaMultiplier *= getInertiaMultiplierWeapon();
		
		////////////////////////
		// WEAPON BARREL LENGTH
		inertiaMultiplier *= getInertiaMultiplierWeaponLength();
		
		////////////////////////
		// PLAYER INVENTORY WEIGHT
		inertiaMultiplier *= getInertiaMultiplierInventoryWeight();
				
		////////////////////////
		// HIPFIRE 
		inertiaMultiplier *= getInertiaMultiplierHipfire();
		
		return Math.Clamp(inertiaMultiplier, GunplayConstants.INERTIA_MIN_MULTIPLIER, GunplayConstants.INERTIA_MAX_MULTIPLIER);
	}
		
	
	/**
	*	@brief Get the inertia multiplier based on the player stance
	*	 @return float - inertia multiplier
	*/
	protected float getInertiaMultiplierStance() {
		if (getPlayer().IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT | DayZPlayerConstants.STANCEMASK_ERECT)) {
			return GunplayConstants.INERTIA_MULTIPLIER_ERECT;
		} else if (getPlayer().IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDCROUCH | DayZPlayerConstants.STANCEMASK_CROUCH)) {
			return GunplayConstants.INERTIA_MULTIPLIER_CROUCHED;
		} else if (getPlayer().IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE | DayZPlayerConstants.STANCEMASK_PRONE)) {
			return GunplayConstants.INERTIA_MULTIPLIER_PRONE;
		} 
		
		return 1;
	}
	
	/**
	*	@brief Get the inertia multiplier based on the player movement
	*	 @return float - inertia multiplier
	*/
	protected float getInertiaMultiplierMovement() {
		switch (getPlayer().m_MovementState.m_iMovement) { 
			case 0:	return GunplayConstants.INERTIA_MULTIPLIER_STANDING;
			case 1: return GunplayConstants.INERTIA_MULTIPLIER_WALKING;
			case 2:	return GunplayConstants.INERTIA_MULTIPLIER_JOGGING;
		}
		return 1;
	}
	
	/**
	*	@brief Get the inertia multiplier based on the weapon
	*	 @return float - inertia multiplier
	*/
	protected float getInertiaMultiplierWeapon() {
		int w = getWeapon().GetWeight();
		if (w > 5000) return 2.00;
		if (w > 3000) return 1.75;
		if (w > 2000) return 1.50;
		if (w > 1000) return 1.25;
		return 1;
	}
	
	/**
	*	@brief Get the inertia multiplier based on the weapon length
	*	 @return float - inertia multiplier
	*/
	protected float getInertiaMultiplierWeaponLength() {
		return getWeapon().getWeaponLength() * GunplayConstants.INERTIA_MULTIPLIER_WEAPON_LENGTH_WEIGHT;
	}
	
	/**
	*	@brief Get the inertia multiplier based on the weapon
	*	 @return float - inertia multiplier
	*/
	protected float getInertiaMultiplierInventoryWeight() {
		int w = getPlayer().GetWeight();
		if (w > 40000) return 2.00;
		if (w > 20000) return 1.75;
		if (w > 10000) return 1.50;
		if (w > 5000)  return 1.25;
		return 1.00;
	}
	
	/**
	*	@brief Get the hipfire inertia multiplier
	*	 @return float - inertia multiplier
	*/
	protected float getInertiaMultiplierHipfire() {
		if (!getPlayer().IsInOptics() && !getPlayer().IsInIronsights()) {
			return GunplayConstants.INERTIA_MULTIPLIER_HIPFIRE;
		}
		return 1;
	}

}