class JSA_Base_2F_Kit extends Msp_Kit
{
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
		if (GetGame().IsServer())
		{
			JSA_Base_2F building = JSA_Base_2F.Cast(GetGame().CreateObjectEx("JSA_Base_2F", position, ECE_PLACE_ON_SURFACE));
			building.SetPosition(position);
			building.SetOrientation(orientation);
			building.Update();

			this.Delete();
		}
	}
};
