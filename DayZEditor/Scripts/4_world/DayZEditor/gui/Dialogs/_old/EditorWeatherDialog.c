
class EditorEnvironmentDialogController: DialogBaseController
{
	protected World m_World;
	protected Weather m_Weather;
		
	float time;
	float rain;
	float fog;
	float overcast;
	float wind;
	float exposure;
	bool lighting;
	
	void SetWorld(World world)
	{
		EditorLog.Trace("EditorEnvironmentDialogController::SetWorld");
		m_World = world;
		m_Weather = GetGame().GetWeather();
		
		int year, month, day, hour, minute;
		m_World.GetDate(year, month, day, hour, minute);
		time = minute * 60 + hour * 3600;
		
		rain = m_Weather.GetRain().GetActual();
		fog = m_Weather.GetFog().GetActual();
		overcast = m_Weather.GetOvercast().GetActual();
		
		m_Weather.SetWindMaximumSpeed(100);
		wind = m_Weather.GetWindSpeed();
		
		exposure = GetGame().GetWorld().GetEyeAccom();
		
	}
	
	override void PropertyChanged(string property_name)
	{
		
		switch (property_name) {
			
			case "time": {
				int year, month, day, hour, minute;
				m_World.GetDate(year, month, day, hour, minute);
				hour = Math.Floor(time / 3600); 
				minute = time / 60 - hour * 60;
				m_World.SetDate(year, month, day, hour, minute);
				
				break;
			}
			
			case "rain": {
				m_Weather.GetRain().Set(rain);				
				break;
			}
			
			case "fog": {
				m_Weather.GetFog().Set(fog);
				break;
			}
			
			case "overcast": {
				m_Weather.GetOvercast().Set(overcast);
				break;
			}
			
			case "wind": {
				m_Weather.SetWindSpeed(wind);
				break;
			}
			
			case "exposure": {
				GetGame().GetWorld().SetEyeAccom(exposure);
				break;
			}
			
			case "lighting": {
						
				if (lighting) {
					GetGame().GetWorld().LoadNewLightingCfg("dz\\data\\lighting\\lighting_darknight.txt");
				} else {
					GetGame().GetWorld().LoadNewLightingCfg("dz\\data\\lighting\\lighting_default.txt");
				}
				
				break;
			}
		}	
	}
}

class EditorEnvironmentDialog: EditorDialog
{
	protected ref EditorEnvironmentDialogController m_EditorWeatherDialogController;
	
	
	void EditorEnvironmentDialog(Widget parent = null)
	{
		EditorLog.Trace("EditorEnvironmentDialog");
		m_EditorWeatherDialogController = EditorEnvironmentDialogController.Cast(m_Controller);
		m_EditorWeatherDialogController.SetWorld(GetGame().GetWorld());
		
		/*EditorPrefabGroup weather_group = new EditorPrefabGroup("Weather");
		
		weather_group.AddPrefab(new EditorPrefabSlider("Time", "time", 0, 86400));
		weather_group.AddPrefab(new EditorPrefabSlider("Rain", "rain", 0, 1));
		weather_group.AddPrefab(new EditorPrefabSlider("Fog", "fog", 0, 1));
		weather_group.AddPrefab(new EditorPrefabSlider("Overcast", "overcast", 0, 1));
		weather_group.AddPrefab(new EditorPrefabSlider("Wind", "wind", 0, 100));
		weather_group.AddPrefab(new EditorPrefabSlider("Exposure", "exposure", 0, 1));
		weather_group.AddPrefab(new EditorPrefabButton("Lighting", "lighting"));
		weather_group.SetController(m_EditorWeatherDialogController);
		
		AddContent(weather_group);
		SetTitle("World Controller");
		AddButton("Close", "DialogCloseRoutedUICommand");*/
	}
	
	override typename GetControllerType() {
		return EditorEnvironmentDialogController;
	}
}
