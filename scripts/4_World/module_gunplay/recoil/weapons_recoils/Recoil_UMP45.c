modded class Ump45Recoil {
	override void initRecoilParameters() {
		handsRanges        = {-0.060, 0.750,  1.450 ,  1.785};	
		handsAccumSpeed    = 0.975;
		handsResetSpeed    = 0.550;
		
		misalignIntensity  = {0.250, 0.250};
		misalignAccumSpeed = 0.855;
		misalignResetSpeed = 0.600;
	
		mouseRanges        = { 0.175, 0.250,  1.250,  1.750};
		mouseTime          = 0.150;
	
		kick               = 0.025;
		kickResetTime      = 2.250;
	}

	override void Init() {
		m_handsMinHorizontalRecoil = -0.060;
		m_handsMaxHorizontalRecoil = 0.075;
		
		m_handsMinVerticalRecoil = 0.475;
		m_handsMaxVerticalRecoil = 0.795;
		m_handsRecoilsteps = 2;
		
		m_HandsOffsetRelativeTime = 2;
		
		m_relativeReloadTime = 2.5;
		
		m_MouseOffsetRangeMin = 88;
		m_MouseOffsetRangeMax = 105;
		m_MouseOffsetDistance = 2.28;
		m_MouseOffsetRelativeTime = 0.2;
	
		m_CamOffsetDistance = 0.020;
		m_CamOffsetRelativeTime = 1;
		
		createHandRecoilPoints();
	}
}