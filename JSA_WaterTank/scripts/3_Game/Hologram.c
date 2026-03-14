modded class Hologram
{
	override bool CanObjBeGrabbed(EntityAI object)
	{
		if (object.IsKindOf("JSA_WaterTank"))
			return true;

		return super.CanObjBeGrabbed(object);
	}
}
