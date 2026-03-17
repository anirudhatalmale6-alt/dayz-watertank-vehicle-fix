class JSA_Base_2F_Kit extends ItemBase
{
	string GetBuildingClass()
	{
		return "JSA_Base_2F";
	}

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
		if (GetGame().IsServer())
		{
			Print("[JSA_BaseKits] Placing JSA_Base_2F at position: " + position.ToString());

			// ECE_PLACE_ON_SURFACE snaps model origin to terrain — handles slopes/hills on Deer Isle
			Object building = GetGame().CreateObjectEx("JSA_Base_2F", position, ECE_PLACE_ON_SURFACE);
			if (building)
			{
				building.SetPosition(position);
				building.SetOrientation(orientation);

				// ch_bases models have origin at center, not bottom
				// Read bounding box and raise so bottom sits at terrain surface
				vector mins, maxs;
				building.ClippingInfo(mins, maxs);
				float raiseBy = 0;
				if (mins[1] < 0)
				{
					raiseBy = -mins[1];
				}
				else
				{
					raiseBy = 4.0;
				}

				Print("[JSA_BaseKits] BBox mins=" + mins.ToString() + " maxs=" + maxs.ToString() + " raiseBy=" + raiseBy.ToString());

				vector adjustedPos = building.GetPosition();
				adjustedPos[1] = adjustedPos[1] + raiseBy;
				building.SetPosition(adjustedPos);

				building.Update();
				Print("[JSA_BaseKits] Final position: " + building.GetPosition().ToString());
			}

			this.Delete();
		}
		SetIsDeploySound(true);
	}

	override bool IsBasebuildingKit()
	{
		return true;
	}

	override bool IsDeployable()
	{
		return true;
	}

	override string GetDeploySoundset()
	{
		return "placeHescoBox_SoundSet";
	}

	override string GetLoopDeploySoundset()
	{
		return "hescobox_deploy_SoundSet";
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};
