class JSA_Base_2FLift_Kit extends Msp_Kit
{
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		// Do NOT call super — Msp_Kit's OnPlacementComplete creates a duplicate building
		if (GetGame().IsServer())
		{
			// position already includes terrain height + itemPlacingPos offset from hologram
			JSA_Base_2FLift building = JSA_Base_2FLift.Cast(GetGame().CreateObjectEx("JSA_Base_2FLift", position, ECE_PLACE_ON_SURFACE));
			building.SetPosition(position);
			building.SetOrientation(orientation);
			// Do NOT call Update() — it re-snaps to terrain surface, undoing the height offset

			this.Delete();
		}
		SetIsPlaceSound(true);
	}
};
