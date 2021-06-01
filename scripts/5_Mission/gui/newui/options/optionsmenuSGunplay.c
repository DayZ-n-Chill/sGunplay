class OptionsMenuSGunplay : SOptionsMenuTab{
	
	override string getLayoutName(){
		return "MyMODS/sGunplay/scripts/5_Mission/gui/newui/options/sGunplay_tab.layout";
	}
	
	protected ref SUserConfigGunplay m_sUserConfig;
	
	static const string WN_LENSZOOM                = "sude_lensZoom_setting_";
	static const string WN_ADS_DOF_INTENSITY       = "sude_adsDOFIntensity_setting_";
	static const string WN_HIDE_BARREL             = "sude_hideBarrel_setting_";
	static const string WN_HIDE_CLOTHING           = "sude_hideClothing_setting_";
	static const string WN_DYNAMIC_CROSSHAIR       = "sude_dynamicCrosshair_setting_";
	
	static const string WN_RESET_DEADZONE_ON_FOCUS = "sude_resetOnFocus_setting_";
	static const string WN_DEADZONE_UP_DOWN        = "sude_deadzone_UpDown_setting_";
	static const string WN_DEADZONE_LEFT_RIGHT     = "sude_deadzone_LeftRight_setting_";
	static const string WN_DEADZONE_UP             = "sude_deadzoneUp_setting_";
	static const string WN_DEADZONE_RIGHT          = "sude_deadzoneRight_setting_";
	static const string WN_DEADZONE_DOWN           = "sude_deadzoneDown_setting_";
	static const string WN_DEADZONE_LEFT           = "sude_deadzoneLeft_setting_";	
	
	
	protected ref SliderWidget              m_lensZoomSlider;
	protected ref TextWidget                m_lensZoomValue;
	
	protected ref SliderWidget              m_adsDOFIntensitySlider;
	protected ref TextWidget                m_adsDOFIntensityValue;
	
	protected ref CheckBoxWidget            m_hideBarrel;
	protected ref CheckBoxWidget            m_hideClothing;
	
	protected ref CheckBoxWidget            m_dynamicCrosshair;
	
	protected ref CheckBoxWidget            m_resetDeadzoneOnFocus;
	
	protected ref SliderWidget              m_deadzoneUpDownSlider;
	protected ref TextWidget                m_deadzoneUpDownValue;
	
	protected ref SliderWidget              m_deadzoneLeftRightSlider;
	protected ref TextWidget                m_deadzoneLeftRightValue;
	
	protected ref SliderWidget              m_deadzoneUpSlider;
	protected ref TextWidget                m_deadzoneUpValue;
	
	protected ref SliderWidget              m_deadzoneRightSlider;
	protected ref TextWidget                m_deadzoneRightValue;
	
	protected ref SliderWidget              m_deadzoneDownSlider;
	protected ref TextWidget                m_deadzoneDownValue;
	
	protected ref SliderWidget              m_deadzoneLeftSlider;
	protected ref TextWidget                m_deadzoneLeftValue;
	
	
	override void onInit(){
		m_sUserConfig = SUserConfig.gunplay();
		super.onInit();
	}
	
	override void initOptionsWidgets(){
		
		init(WN_LENSZOOM, m_lensZoomSlider, m_lensZoomValue,
			m_sUserConfig.getLensZoomStrength(), 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_LENSZOOM", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_LENSZOOM_DESCRIPTION");
		
		init(WN_ADS_DOF_INTENSITY, m_adsDOFIntensitySlider, m_adsDOFIntensityValue,
			m_sUserConfig.getAdsDOFIntensity(), 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_ADS_DOF_INTENSITY", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_ADS_DOF_INTENSITY_DESCRIPTION");
		
		init(WN_HIDE_BARREL, m_hideBarrel,
			m_sUserConfig.isHideWeaponBarrelInOpticEnabled(),
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_HIDE_BARREL",
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_HIDE_BARREL_DESCRIPTION");
		
		init(WN_HIDE_CLOTHING, m_hideClothing,
			m_sUserConfig.isHideClothingInOpticEnabled(),
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_HIDE_CLOTHING",
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_HIDE_CLOTHING_DESCRIPTION");
		
		init(WN_DYNAMIC_CROSSHAIR, m_dynamicCrosshair,
			m_sUserConfig.isDynamicCrosshairEnabled(),
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DYNAMIC_CROSSHAIR",
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DYNAMIC_CROSSHAIR");
		
		init(WN_RESET_DEADZONE_ON_FOCUS, m_resetDeadzoneOnFocus,
			m_sUserConfig.isResetDeadzoneOnFocusEnabled(),
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE",
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE_RESET_ON_FOCUS_DESCRIPTION");
		
		
		
		TFloatArray deadzoneLimits = m_sUserConfig.getDeadzoneLimits();
		
		init(WN_DEADZONE_UP_DOWN, m_deadzoneUpDownSlider, m_deadzoneUpDownValue,
			deadzoneLimits[0], 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE_UPDOWN_DESCRIPTION");
		
		init(WN_DEADZONE_LEFT_RIGHT, m_deadzoneLeftRightSlider, m_deadzoneLeftRightValue,
			deadzoneLimits[1], 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE_LEFTRIGHT_DESCRIPTION");
		
		init(WN_DEADZONE_UP, m_deadzoneUpSlider, m_deadzoneUpValue,
			deadzoneLimits[0], 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE_UP_DESCRIPTION");
		
		init(WN_DEADZONE_RIGHT, m_deadzoneRightSlider, m_deadzoneRightValue,
			deadzoneLimits[1], 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE_RIGHT_DESCRIPTION");
		
		init(WN_DEADZONE_DOWN, m_deadzoneDownSlider, m_deadzoneDownValue,
			deadzoneLimits[2], 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE_DOWN_DESCRIPTION");
		m_deadzoneDownValue.SetText("-"+deadzoneLimits[2]);
		
		init(WN_DEADZONE_LEFT, m_deadzoneLeftSlider, m_deadzoneLeftValue,
			deadzoneLimits[3], 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE", 
			"#STR_SUDE_LAYOUT_OPTIONS_GUNPLAY_DEADZONE_LEFT_DESCRIPTION");
		m_deadzoneLeftValue.SetText("-"+deadzoneLimits[3]);
	}
	
	
	override void onChange(SliderWidget w, int x, int y, bool finished){
		switch(s.GetName()){
			case WN_LENSZOOM+"option":
				updateLensZoomOption(s.GetCurrent());
				break;
			case WN_ADS_DOF_INTENSITY+"option":
				updateAdsDOFIntensity(s.GetCurrent());
				break;
			
			case WN_DEADZONE_UP_DOWN+"option":
				updateDeadzoneOption(0, s.GetCurrent());
				m_deadzoneUpSlider.SetCurrent(s.GetCurrent());
				updateDeadzoneOption(2, s.GetCurrent());
				m_deadzoneDownSlider.SetCurrent(s.GetCurrent());
				m_deadzoneUpDownValue.SetText(s.GetCurrent().ToString());
				break;
			case WN_DEADZONE_LEFT_RIGHT+"option":
				updateDeadzoneOption(1, s.GetCurrent());
				m_deadzoneLeftSlider.SetCurrent(s.GetCurrent());
				updateDeadzoneOption(3, s.GetCurrent());
				m_deadzoneRightSlider.SetCurrent(s.GetCurrent());
				m_deadzoneLeftRightValue.SetText(s.GetCurrent().ToString());
				break;				
			case WN_DEADZONE_UP+"option":
				updateDeadzoneOption(0, s.GetCurrent());
				break;
			case WN_DEADZONE_RIGHT+"option":
				updateDeadzoneOption(1, s.GetCurrent());
				break;
			case WN_DEADZONE_DOWN+"option":
				updateDeadzoneOption(2, s.GetCurrent());
				break;
			case WN_DEADZONE_LEFT+"option":
				updateDeadzoneOption(3, s.GetCurrent());
				break;
			
			default: SLog.w("No slider widget name found.","OptionsMenuSGunplay::OnChange");
		}
	}
	
	
	override void onChange(CheckBoxWidget c, int x, int y, bool finished){
		switch(c.GetName()){
			case WN_HIDE_BARREL+"option":
				updateHideParrelOption(c.IsChecked());
				break;
			case WN_HIDE_CLOTHING+"option":
				updateHideClothingOption(c.IsChecked());
				break;
			case WN_DYNAMIC_CROSSHAIR+"option":
				updateDynamicCrosshairOption(c.IsChecked());
				break;
			case WN_RESET_DEADZONE_ON_FOCUS+"option":
				updateResetDeadzoneOnFocus(c.IsChecked());
				break;
			default: SLog.w("No checkbox  widget name found.","OptionsMenuSGunplay::OnChange");
		}
	}

		
	void updateLensZoomOption( float newValue){
		m_lensZoomValue.SetText(newValue.ToString());
		m_sUserConfig.setLensZoomStrength(newValue);
		onConfigChange();
	}
	
	void updateAdsDOFIntensity(float newValue){
		m_adsDOFIntensityValue.SetText(newValue.ToString());
		m_sUserConfig.setAdsDOFIntensity(newValue);	
		onConfigChange();
	}
	
	void updateResetDeadzoneOnFocus(bool enabled){
		m_sUserConfig.resetDeadzoneOnFocus(enabled);
		onConfigChange();
	}
	
	void updateDeadzoneOption(int i, float newValue){
		switch(i){
			case 0 :
				m_deadzoneUpValue.SetText(newValue.ToString());
				break;
			case 1 :
				m_deadzoneRightValue.SetText(newValue.ToString());
				break;
			case 2 :
				m_deadzoneDownValue.SetText("-"+newValue.ToString());
				break;
			case 3 :
				m_deadzoneLeftValue.SetText("-"+newValue.ToString());
				break;
			default: SLog.w("Wrong deadzone");
		}
		m_sUserConfig.setDeadzoneLimit(i, newValue);
		onConfigChange();
	}
		
	void updateHideParrelOption(bool enabled){
		m_sUserConfig.hideWeaponBarrelInOptic(enabled);
		onConfigChange();
	}
	
	void updateHideClothingOption(bool enabled){
		m_sUserConfig.hideClothingInOptic(enabled);
		onConfigChange();
	}
	
	void updateDynamicCrosshairOption(bool enabled){
		m_sUserConfig.setDynamicCrosshairEnabled(enabled);
		onConfigChange();
	}
	
	void UpdateBodyClipAllContactOption( bool enabled){
		PluginSDebug.bodyClipAllContact_enabled = enabled;
	}
	
	void UpdateBodyClipContactPosOption( bool enabled){
		PluginSDebug.bodyClipContactPos_enabled = enabled;
	}
	
	void UpdateDebugCrosshairOption( bool enabled){
		PluginSDebug.crosshair_enabled = enabled;
	}
	
	override void onConfigChange(){ //@todo lol change this shit
		m_sUserConfig.save();
	}
	
	
}