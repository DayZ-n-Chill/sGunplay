modded class Colt1911Recoil{
	
	override void Init(){
		m_handsMinHorizontalRecoil = -0.1;
		m_handsMaxHorizontalRecoil = 0.125;
		
		m_handsMinVerticalRecoil = 0.565;
		m_handsMaxVerticalRecoil = 0.875;
		m_handsRecoilsteps = 2;
		
		m_HandsOffsetRelativeTime = 3;
		
		m_relativeReloadTime = 2.5;
		
		m_MouseOffsetRangeMin = 55;
		m_MouseOffsetRangeMax = 90;
		m_MouseOffsetDistance = 2.8;
		m_MouseOffsetRelativeTime = 0.2;
	
		m_CamOffsetDistance = 0.022;
		m_CamOffsetRelativeTime = 1;
		
		createHandRecoilPoints();
	}
}