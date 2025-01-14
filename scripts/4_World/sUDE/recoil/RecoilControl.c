class RecoilControl : Managed {
	
	protected PlayerBase m_player;
	protected float m_control;
	
	void RecoilControl(PlayerBase player) {
		m_player = player;
		compute();
	}
	
	float get() {
		return m_control;
	}
	
	void compute() {
		m_control = 0;
		
		if (GunplayConstants.RECOIL_CONTROL_USE_STRENGTH) {
			m_control += getModifierStrength();
		}
		
		if (GunplayConstants.RECOIL_CONTROL_USE_PLAYER_INVENTORY_WEIGHT) {
			m_control += getModifierInventoryWeight();
		}
		
		if (GunplayConstants.RECOIL_CONTROL_USE_STANCE) {
			m_control += getModifierStance();
		}
		
		if (GunplayConstants.RECOIL_CONTROL_USE_MOVEMENT) {
			m_control += getModifierMovement();
		}
		
		m_control = Math.Clamp(m_control, GunplayConstants.RECOIL_CONTROL_MINIMUM, GunplayConstants.RECOIL_CONTROL_MAXIMUM);
	}
	
	/**
	*	@brief compute the recoil control based on strength
	*	@return float - recoil control modifier
	*/
	protected float getModifierStrength() {
		return m_player.GetSoftSkillsManager().GetSpecialtyLevel() * GunplayConstants.RECOIL_CONTROL_STRENGTH_WEIGHT;
	}
	
	/**
	*	@brief compute the recoil control based on the player inventory weight
	*	@return float - recoil control modifier
	*/
	protected float getModifierInventoryWeight() {
		int w = m_player.GetWeight();
		if (w > 40000) return -0.75;
		if (w > 20000) return -0.50;
		if (w > 10000) return -0.25;
		if (w > 5000)  return  0.25;
		return 0.75;
	}

	/**
	*	@brief Get the recoil control modifier based on the player stance
	*	@return float - recoil control modifier
	*/
	protected float getModifierStance() {
		if (m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT | DayZPlayerConstants.STANCEMASK_ERECT)) {
			return GunplayConstants.RECOIL_CONTROL_STANCE_ERECT;
		}
		
		if (m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDCROUCH | DayZPlayerConstants.STANCEMASK_CROUCH)) {
			return GunplayConstants.RECOIL_CONTROL_STANCE_CROUCHED;
		}
		
		if (m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE | DayZPlayerConstants.STANCEMASK_PRONE)) {
			return GunplayConstants.RECOIL_CONTROL_STANCE_PRONE;
		} 
		
		return 1;
	}
	
	/**
	*	@brief Get the recoil control modifier based on the player movement
	*	@return float - recoil control modifier
	*/
	protected float getModifierMovement() {
		switch (m_player.m_MovementState.m_iMovement) {
			case 0:	return GunplayConstants.RECOIL_CONTROL_MOVEMENT_STANDING;			
			case 1:	return GunplayConstants.RECOIL_CONTROL_MOVEMENT_WALKING;
			case 2:	return GunplayConstants.RECOIL_CONTROL_MOVEMENT_JOGGING;
		}
		return 0;
	}
}