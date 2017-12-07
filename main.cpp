#include "./PKMN_Tools/PKMN_Table.h"
#include "./PKMN_Pokemon/PKMN_Type.h"
#include "./PKMN_Tools/PKMN_Conversion.h"
#include "./PKMN_Tools/PKMN_StatSet.h"
#include "./PKMN_Pokemon/PKMN_ExpAndLevel.h"
#include "./PKMN_Pokemon/PKMN_Moves.h"
#include "./PKMN_Pokemon/PKMN_Pokemon.h"

using namespace std;

int main()
{
    srand(time(NULL));
//    PKMN_Table table("TypeChart.txt");
//    //cout << table;
//    PKMN_Table table2("TypeChart.txt");
////    PKMN_Type t(table.getLineValuesWithLineName("Fire"));
////    PKMN_Type t2(table.getLineValuesWithLineName("Water"));
////    cout << PKMN_Type_message(t2.effectiveness(t));
//    PKMN_StatSet Base(45,49,49,65,65,45);
//    PKMN_StatSet IV;
//    PKMN_StatSet EV(0,0,0,0,0,0);
//    cout << NormalStatistics(Base, IV, EV, 100, "");
//    PKMN_ExpAndLevel lvl("FAST",0, 10);
//    cout << lvl.getLevel() << "," << lvl.getExperience() << endl;
//    unsigned int compteur = 0;
//    while(compteur <= 2000)
//    {
//        lvl.addExperience(100);
//        cout << lvl.getLevel() << "," << lvl.getExperience()<< endl;
//        compteur ++;
//    }
//    PKMN_Table table3(PATH_TO_TYPE_FILE);//"./PKMN_Data/PokedexBaseStat.txt");
//    cout << table3;
//    cout << endl << endl;
//    vector_print(table3.getColumnValuesWithColumnName("Def"));
//    cout << table3("37", "Species");
//    PKMN_Type t1("FIRE");
//    PKMN_Type t2("BUG");
//    cout << endl << t1.effectiveness(t2);
//
//    std::string m_InternalName("MEGAHORN");
//    unsigned int m_ID(1);
//    std::string m_DisplayName("Megahorn");
//    std::string m_FunctionCode("000"); // Hexadecimal number
//    unsigned int m_BasePower(120);
//    PKMN_Type m_Type("BUG");
//    std::string m_DamageCategory("Physical");
//    unsigned int m_Accuracy(85);
//    unsigned int m_TotalPP(10);
//    unsigned int m_AdditionalEffectChance(0);
//    std::string m_Target("00");
//    int m_Priority(0);
//    std::string m_Flags("abef");
//    std::string m_Description("Using its tough and impressive horn, the user rams into the target with no letup.");
    PKMN_Table table(PATH_TO_MOVES_FILE);
    cout << table << endl;
    PKMN_Moves m1("STRUGGLEBUG");
    PKMN_Type m("FIRE");
//    PKMN_Type fire("FIRE");
//    PKMN_Type water("STEEL");
//    PKMN_Type ice("GRASS");
//    std::pair<PKMN_Type, PKMN_Type> t(water, ice);
//    std::cout << typeEffectiveness(fire, t);
}
