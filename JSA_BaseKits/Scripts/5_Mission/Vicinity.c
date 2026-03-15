modded class VicinityItemManager
{
    override bool IsObstructed(Object filtered_object)
    {
        if (filtered_object.IsInherited(JSA_Base_2F) || filtered_object.IsInherited(JSA_Base_2FLift))
            return false;
        return super.IsObstructed(filtered_object);
    }
};
