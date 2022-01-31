modded class FALRecoil{
	
	override void Init(){
		m_handsMinHorizontalRecoil = -0.05;
		m_handsMaxHorizontalRecoil = 0.08;
		
		m_handsMinVerticalRecoil = 1.3225;
		m_handsMaxVerticalRecoil = 1.36;
		m_handsRecoilsteps = 2;
		
		m_HandsOffsetRelativeTime = 1.8;
		
		m_relativeReloadTime = 2.5;
		
		m_MouseOffsetRangeMin = 65;//in degrees min
		m_MouseOffsetRangeMax = 140;//in degrees max
		m_MouseOffsetDistance = 4.15;//how far should the mouse travel
		m_MouseOffsetRelativeTime = 0.25;//[0..1] a time it takes to move the mouse the required distance relative to the reload time of the weapon(firing mode)
	
		m_CamOffsetDistance = 0.045;
		m_CamOffsetRelativeTime = 0.85;	
		
		createHandRecoilPoints();
	}
}