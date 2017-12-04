#include "PKMN_Type.h"

PKMN_Type::PKMN_Type():
    m_InternalName(),
    m_Weaknesses(),
    m_Immunities(),
    m_Resistances(),
    m_IsSpecialType(false)
{

}


PKMN_Type::PKMN_Type(std::string InternalName,
              std::string Weaknesses,
              std::string Immunities,
              std::string Resistances,
              std::string IsSpecialType)
{
    m_InternalName = InternalName;
    m_Weaknesses = string_split(Weaknesses, ',');
    m_Immunities = string_split(Immunities, ',');
    m_Resistances = string_split(Resistances, ',');
    m_IsSpecialType = str_to_bool(IsSpecialType);
}

double PKMN_Type::effectiveness(PKMN_Type const Type_att) const
{
    if(vector_in(m_Immunities, Type_att.m_InternalName))
    {
        return INEFFECTIVE;
    }
    else if(vector_in(m_Weaknesses, Type_att.m_InternalName))
    {
        return SUPER_EFFECTIVE;
    }
    else if(vector_in(m_Resistances, Type_att.m_InternalName))
    {
        return NOT_VERY_EFFECTIVE;
    }
    else
    {
        return NORMAL_EFFECTIVENESS;
    }
}

std::pair<double,std::string> PKMN_Type::effectiveness(std::pair<PKMN_Type, PKMN_Type> PairType_att)
{
    double typeMultFactor = this->effectiveness(PairType_att.first) * this->effectiveness(PairType_att.second);
    std::string message("");
    if(typeMultiplicativeFactor == INEFFECTIVE)
    {
        message = "It's totally ineffective !";
    }
    else if(typeMultiplicativeFactor < NORMAL_EFFECTIVENESS)
    {
        message = "It's not very effective !";
    }
    else if(typeMultiplicativeFactor > NORMAL_EFFECTIVENESS)
    {
        message = "It's super effective !";
    }
    return std::pair<double,std::string>(typeMultFactor, message);
}


std::string PKMN_Type::effectivenessMessage(PKMN_Type const Type_att)
{
    if(TypeMultiplicativeFactor == INEFFECTIVE)
    {
        return "It's totally ineffective !";
    }
    else if(TypeMultiplicativeFactor < NORMAL_EFFECTIVENESS)
    {
        return "It's not very effective !";
    }
    else if(TypeMultiplicativeFactor > NORMAL_EFFECTIVENESS)
    {
        return "It's super effective !";
    }
    return "";
}


//std::string typeName(PKMN_Type InternalName)
//{
//	if(InternalName == NORMAL)
//		return "Normal";
//	else if(InternalName == FIGHTING)
//		return "Fighting";
//	else if(InternalName == FLYING)
//		return "Flying";
//	else if(InternalName == POISON)
//		return "Poison";
//	else if(InternalName == GROUND)
//		return "Ground";
//	else if(InternalName == ROCK)
//		return "Rock";
//	else if(InternalName == BUG)
//		return "Bug";
//	else if(InternalName == GHOST)
//		return "Ghost";
//	else if(InternalName == STEEL)
//		return "Steel";
//	else if(InternalName == FIRE)
//		return "Fire";
//	else if(InternalName == WATER)
//		return "Water";
//	else if(InternalName == GRASS)
//		return "Grass";
//	else if(InternalName == ELECTRIC)
//		return "Electric";
//	else if(InternalName == PSYCHIC)
//		return "Psychic";
//	else if(InternalName == ICE)
//		return "Ice";
//	else if(InternalName == DRAGON)
//		return "Dragon";
//	else if(InternalName == DARK)
//		return "Dark";
//	return "";
//}
//
//double typeEffectiveness(PKMN_Type typeAtt, PKMN_Type typeDef)
//{
//	if(typeDef == NORMAL)
//	{
//		if(typeAtt == GHOST)
//			return INEFFECTIVE;
//		else if(typeAtt == FIGHTING)
//			return SUPER_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == FIGHTING)
//	{
//		if(typeAtt == FLYING || typeAtt == PSYCHIC)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == ROCK || typeAtt == BUG || typeAtt == DARK)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == FLYING)
//	{
//		if(typeAtt == GROUND)
//			return INEFFECTIVE;
//		else if(typeAtt == ROCK || typeAtt == ELECTRIC || typeAtt == ICE)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == FIGHTING || typeAtt == BUG || typeAtt == GRASS)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == POISON)
//	{
//		if(typeAtt == GROUND || typeAtt == PSYCHIC)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == FIGHTING || typeAtt == POISON || typeAtt == BUG || typeAtt == GRASS)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == GROUND)
//	{
//		if(typeAtt == ELECTRIC)
//			return INEFFECTIVE;
//		else if(typeAtt == WATER || typeAtt == GRASS || typeAtt == ICE)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == POISON || typeAtt == ROCK)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == ROCK)
//	{
//		if(typeAtt == FIGHTING || typeAtt == GROUND || typeAtt == STEEL || typeAtt == WATER || typeAtt == GRASS)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == NORMAL || typeAtt == FLYING || typeAtt == POISON || typeAtt == FIRE)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == BUG)
//	{
//		if(typeAtt == FLYING || typeAtt == ROCK || typeAtt == FIRE)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == FIGHTING || typeAtt == GROUND || typeAtt == GRASS)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == GHOST)
//	{
//		if(typeAtt == NORMAL || typeAtt == FIGHTING)
//			return INEFFECTIVE;
//		else if(typeAtt == GHOST || typeAtt == DARK)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == POISON || typeAtt == BUG)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == STEEL)
//	{
//		if(typeAtt == POISON)
//			return INEFFECTIVE;
//		else if(typeAtt == FIGHTING || typeAtt == GROUND || typeAtt == FIRE)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == NORMAL || typeAtt == FLYING || typeAtt == ROCK || typeAtt == BUG || typeAtt == GHOST || typeAtt == STEEL || typeAtt == GRASS || typeAtt == PSYCHIC || typeAtt == ICE || typeAtt == DRAGON || typeAtt == DARK)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == FIRE)
//	{
//		if(typeAtt == GROUND || typeAtt == ROCK || typeAtt == WATER)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == BUG || typeAtt == STEEL || typeAtt == FIRE || typeAtt == GRASS || typeAtt == ICE)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == WATER)
//	{
//		if(typeAtt == GRASS || typeAtt == ELECTRIC)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == STEEL || typeAtt == FIRE || typeAtt == WATER || typeAtt == ICE)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == GRASS)
//	{
//		if(typeAtt == FLYING || typeAtt == POISON || typeAtt == BUG || typeAtt == FIRE || typeAtt == ICE)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == GROUND || typeAtt == WATER || typeAtt == GRASS || typeAtt == ELECTRIC)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == ELECTRIC)
//	{
//		if(typeAtt == GROUND)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == FLYING || typeAtt == STEEL || typeAtt == ELECTRIC)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == PSYCHIC)
//	{
//		if(typeAtt == BUG || typeAtt == GHOST || typeAtt == DARK)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == FIGHTING || typeAtt == PSYCHIC)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == ICE)
//	{
//		if(typeAtt == FIGHTING || typeAtt == ROCK || typeAtt == STEEL || typeAtt == FIRE)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == ICE)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == DRAGON)
//	{
//		if(typeAtt == ICE || typeAtt == DRAGON)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == FIRE || typeAtt == WATER || typeAtt == GRASS || typeAtt == ELECTRIC)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	else if(typeDef == DARK)
//	{
//		if(typeAtt == PSYCHIC)
//			return INEFFECTIVE;
//		else if(typeAtt == FIGHTING || typeAtt == BUG)
//			return SUPER_EFFECTIVE;
//		else if(typeAtt == GHOST || typeAtt == DARK)
//			return NOT_VERY_EFFECTIVE;
//		else
//			return NORMAL_EFFECTIVENESS;
//	}
//	return NORMAL_EFFECTIVENESS;
//}
