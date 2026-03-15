class ActionDismantleJSA_Base2FLiftCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(30);
    }
};

class ActionDismantleJSA_Base2FLift : ActionContinuousBase
{
    void ActionDismantleJSA_Base2FLift()
    {
        m_CallbackClass = ActionDismantleJSA_Base2FLiftCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
        m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNonRuined(UAMaxDistances.BASEBUILDING);
    }

    override string GetText() { return "Dismantle Base"; }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!item || !item.IsInherited(Screwdriver))
            return false;
        return JSA_Base_2FLift.Cast(target.GetObject()) != null;
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        JSA_Base_2FLift building = JSA_Base_2FLift.Cast(action_data.m_Target.GetObject());
        if (building)
        {
            vector pos = action_data.m_Player.GetPosition();
            building.Delete();
            action_data.m_MainItem.DecreaseHealth(100, true);
            GetGame().CreateObject("JSA_Base_2FLift_Kit", pos);
        }
        action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
    }

    override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
    {
        if (super.SetupAction(player, target, item, action_data, extra_data))
        {
            m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
            return true;
        }
        return false;
    }
};
