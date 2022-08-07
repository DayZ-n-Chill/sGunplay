modded class Aks74uRecoil {
	override void initRecoilParameters() {
		handsRanges        = {-1.050, 1.550,  2.250 ,  3.285};	
		handsAccumSpeed    = 0.975;
		handsResetSpeed    = 0.550;
		
		misalignIntensity  = {0.075, 0.075};
		misalignAccumSpeed = 0.975;
		misalignResetSpeed = 0.500;
	
		mouseRanges        = { 0.175, 0.250,  1.250,  1.750};
		mouseTime          = 0.150;
	
		kick               = 0.080;
		kickResetTime      = 2.250;
	}
	
	override void Init() {
		m_handsMinHorizontalRecoil = -0.085;
		m_handsMaxHorizontalRecoil = 0.105;
		
		m_handsMinVerticalRecoil = 0.1875;
		m_handsMaxVerticalRecoil = 0.2325;
		m_handsRecoilsteps = 2;
		
		m_HandsOffsetRelativeTime = 2;
		
		m_relativeReloadTime = 2.5;
		
		m_MouseOffsetRangeMin = 45;
		m_MouseOffsetRangeMax = 110;
		m_MouseOffsetDistance = 2.5;
		m_MouseOffsetRelativeTime = 0.2;
	
		m_CamOffsetDistance = 0.0275;
		m_CamOffsetRelativeTime = 0.85;
		
		createHandRecoilPoints();
	}
}