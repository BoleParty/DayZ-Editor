class EditorLootEditorCommand: EditorCommand
{
	protected override bool Execute(Class sender, CommandArgs args)
	{
		super.Execute(sender, args);
		if (GetEditor().GetObjectManager().CurrentSelectedItem) {
			m_Editor.EditLootSpawns(GetEditor().GetObjectManager().CurrentSelectedItem);
		}
		
		return true;
	}
	
	override string GetName() 
	{
		return "#STR_EDITOR_LOOT_EDITOR";
	}
}