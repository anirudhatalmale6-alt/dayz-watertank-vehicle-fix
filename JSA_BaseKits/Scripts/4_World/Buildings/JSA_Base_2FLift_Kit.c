class JSA_Base_2FLift_Kit extends Msp_Kit
{
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		// Do NOT call super — Msp_Kit's OnPlacementComplete creates a duplicate building
		if (GetGame().IsServer())
		{
			Print("[JSA_BaseKits] Placing JSA_Base_2FLift at position: " + position.ToString());

			// Do NOT use ECE_PLACE_ON_SURFACE — it snaps the building center to ground level,
			// ignoring the Y offset from itemPlacingPos and burying the bottom half
			Object building = GetGame().CreateObjectEx("JSA_Base_2FLift", position, ECE_CREATEPHYSICS);
			if (building)
			{
				building.SetPosition(position);
				building.SetOrientation(orientation);
				Print("[JSA_BaseKits] Building placed at: " + building.GetPosition().ToString());
			}

			this.Delete();
		}
		SetIsPlaceSound(true);
	}
};
