class CfgPatches
{
    class JSA_VehicleGroupInventory
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "HM_Core_Module", "HM_Vehicle_Claim", "LBmaster_Core", "LBmaster_Groups"};
    };
};

class CfgMods
{
    class JSA_VehicleGroupInventory
    {
        dir = "JSA_VehicleGroupInventory";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "JSA Vehicle Group Inventory";
        credits = "";
        author = "BipolarBear";
        authorID = "";
        version = "1.0";
        extra = 0;
        type = "mod";

        dependencies[] = {"World"};

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"JSA_VehicleGroupInventory/Scripts/4_World"};
            };
        };
    };
};
