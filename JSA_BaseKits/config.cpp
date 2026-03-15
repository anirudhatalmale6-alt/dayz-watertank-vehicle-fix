class CfgPatches
{
    class JSA_BaseKits
    {
        units[] = {"JSA_Base_2F_Kit", "JSA_Base_2FLift_Kit"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"ch_bases_one_base", "MuchFramework"};
    };
};

class CfgMods
{
    class JSA_BaseKits
    {
        dir = "JSA_BaseKits";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "JSA_BaseKits";
        credits = "";
        author = "BipolarBear";
        authorID = "0";
        version = "1.0";
        extra = 0;
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"JSA_BaseKits/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"JSA_BaseKits/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"JSA_BaseKits/Scripts/5_Mission"};
            };
        };
    };
};

class CfgVehicles
{
    class ItemBase;
    class JSA_Base_2F_Kit : ItemBase
    {
        scope = 2;
        displayName = "Base Kit (2 Floor)";
        descriptionShort = "Deploy a 2-floor base building.";
        model = "\MuchFramework\data\kitbox\kitbox.p3d";
        weight = 10000;
        itemSize[] = {4, 4};
        canBeDigged = 0;
        class AnimEvents {};
    };

    class JSA_Base_2FLift_Kit : ItemBase
    {
        scope = 2;
        displayName = "Base Kit (2 Floor + Lift)";
        descriptionShort = "Deploy a 2-floor base with lift.";
        model = "\MuchFramework\data\kitbox\kitbox.p3d";
        weight = 10000;
        itemSize[] = {4, 4};
        canBeDigged = 0;
        class AnimEvents {};
    };

    class ch_b_2f_roof_w_n_p;
    class JSA_Base_2F : ch_b_2f_roof_w_n_p
    {
        scope = 2;
        displayName = "JSA Base (2 Floor)";
    };

    class ch_b_2f_lift_w_n_p;
    class JSA_Base_2FLift : ch_b_2f_lift_w_n_p
    {
        scope = 2;
        displayName = "JSA Base (2 Floor + Lift)";
    };
};
