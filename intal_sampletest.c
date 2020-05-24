#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intal.h"

int main(int argc, char const *argv[])
{
    int n = 12;
    char **a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(1001 * sizeof(char));
    }

    strcpy(a[0], "1234512345123451234512345");
    strcpy(a[1], "543215432154321543215432154321");
    strcpy(a[2], "0");
    strcpy(a[3], "1234512345123451234512345");
    strcpy(a[4], "1234512345123451234512344");
    strcpy(a[5], "12");
    strcpy(a[6], "265252859812191058636308480000000");
    strcpy(a[7], "265252859812191058636308480000000");
    strcpy(a[8], "5432154321543215432154321");
    strcpy(a[9], "3");
    
    strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
    char *result1;
    int index1;

    result1 = intal_add(a[0], a[1]);
    if (!result1)
    {
        printf("Test intal_add_1 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "543216666666666666666666666666"))
        {
            printf("Test intal_add_1 PASSED\n");
        }
        else
        {
            printf("Test intal_add_1 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543216666666666666666666666666");
        }
        free(result1);
    }

    result1 = intal_add(a[10], a[11]);
    if (!result1)
    {
        printf("Test intal_add_2 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376"))
        {
            printf("Test intal_add_2 PASSED\n");
        }
        else
        {
            printf("Test intal_add_2 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
        }
        free(result1);
    }

    result1 = intal_add(a[10], a[2]);
    if (!result1)
    {
        printf("Test intal_add_3 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, a[10]))
        {
            printf("Test intal_add_3 PASSED\n");
        }
        else
        {
            printf("Test intal_add_3 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
        }
        free(result1);
    }

    index1 = intal_compare(a[0], a[1]);
    if (-1 == index1)
    {
        printf("Test intal_compare_1 PASSED\n");
    }
    else
    {
        printf("Test intal_compare_1 FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
    }

    index1 = intal_compare(a[6], a[7]);
    if (0 == index1)
    {
        printf("Test intal_compare_2 PASSED\n");
    }
    else
    {
        printf("Test intal_compare_2 FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
    }

    index1 = intal_compare(a[1], a[0]);
    if (1 == index1)
    {
        printf("Test intal_compare_3 PASSED\n");
    }
    else
    {
        printf("Test intal_compare_3 FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
    }

    result1 = intal_diff(a[0], a[1]);
    if (!result1)
    {
        printf("Test intal_diff_1 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "543214197641976419764197641976"))
        {
            printf("Test intal_diff_1 PASSED\n");
        }
        else
        {
            printf("Test intal_diff_1 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
        }
        free(result1);
    }

    result1 = intal_diff(a[0], "0");
    if (!result1)
    {
        printf("Test intal_diff_2 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, a[0]))
        {
            printf("Test intal_diff_2 PASSED\n");
        }
        else
        {
            printf("Test intal_diff_2 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[0]);
        }
        free(result1);
    }

    result1 = intal_diff("10", "11");
    if (!result1)
    {
        printf("Test intal_diff_3 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1"))
        {
            printf("Test intal_diff_3 PASSED\n");
        }
        else
        {
            printf("Test intal_diff_3 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
        }
        free(result1);
    }

    result1 = intal_diff("1234567891", "1234567890");
    if (!result1)
    {
        printf("Test intal_diff_4 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1"))
        {
            printf("Test intal_diff_4 PASSED\n");
        }
        else
        {
            printf("Test intal_diff_4 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
        }
        free(result1);
    }

    result1 = intal_diff("1296462964629646296462978", "864308643086430864308647");
    if (!result1)
    {
        printf("Test intal_diff_5 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "432154321543215432154331"))
        {
            printf("Test intal_diff_5 PASSED\n");
        }
        else
        {
            printf("Test intal_diff_5 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "432154321543215432154331");
        }
        free(result1);
    }

    result1 = intal_multiply(a[5], a[8]);
    if (!result1)
    {
        printf("Test intal_multiply_1 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "65185851858518585185851852"))
        {
            printf("Test intal_multiply_1 PASSED\n");
        }
        else
        {
            printf("Test intal_multiply_1 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "65185851858518585185851852");
        }
        free(result1);
    }

    result1 = intal_multiply(a[8], "1");
    if (!result1)
    {
        printf("Test intal_multiply_2 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, a[8]))
        {
            printf("Test intal_multiply_2 PASSED\n");
        }
        else
        {
            printf("Test intal_multiply_2 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[8]);
        }
        free(result1);
    }

    result1 = intal_multiply(a[8], "8");
    if (!result1)
    {
        printf("Test intal_multiply_3 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "43457234572345723457234568"))
        {
            printf("Test intal_multiply_3 PASSED\n");
        }
        else
        {
            printf("Test intal_multiply_3 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "43457234572345723457234568");
        }
        free(result1);
    }

    result1 = intal_multiply("517638476156374826483643", "123456789123456787654321");
    if (!result1)
    {
        printf("Test intal_multiply_4 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "63905984193025081390646596804795405674644771403"))
        {
            printf("Test intal_multiply_4 PASSED\n");
        }
        else
        {
            printf("Test intal_multiply_4 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "63905984193025081390646596804795405674644771403");
        }
        free(result1);
    }

    result1 = intal_multiply("51763847615637482648364387483647389400374657370012", "123456789123456787654321");
    if (!result1)
    {
        printf("Test intal_multiply_5 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "6390598419302508139064670480929748071517446714872621686438097856447621852"))
        {
            printf("Test intal_multiply_5 PASSED\n");
        }
        else
        {
            printf("Test intal_multiply_5 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "6390598419302508139064670480929748071517446714872621686438097856447621852");
        }
        free(result1);
    }

    result1 = intal_multiply("1234567891234567890012345678912345678900231456789012345678902222222226484738474837737383373778474938", "1234567891234567890012345678912345678900231456789012345678902222222226484738474837737383373777777777");
    if (!result1)
    {
        printf("Test intal_multiply_6 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1524157878067367851592745232580399457031969155528033570601942102777816755869970544406584040092674522948408347156870424915955636314084216327002653893463244207829066128262171964844460832588201727852826"))
        {
            printf("Test intal_multiply_6 PASSED\n");
        }
        else
        {
            printf("Test intal_multiply_6 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1524157878067367851592745232580399457031969155528033570601942102777816755869970544406584040092674522948408347156870424915955636314084216327002653893463244207829066128262171964844460832588201727852826");
        }
        free(result1);
    }

    result1 = intal_multiply("123456789123456789001234567891234567890023145678901234567890222222222648473847483773738337377847493848329048392053721647310946732156372641037416032174917484391206483216489316489316498648916439619843126984631984638912468934738274872358748235784275865481247387657846878718781785756846548167548342175817483172458350415647816438143", "1234567891234567890012345678912345678900231456789012345678902222222226484738474837737383373777777777473128974583291568249365763647321647836219473615743657348126783261457863271657432167382764897382194738921748371240832814738174837819743856387473847181743891074831256478196247896574574173748317483165839109473843124372164738164783153714637140146371463782104312463715463218756372146372104");
    if (!result1)
    {
        printf("Test intal_multiply_7 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "152415787806736785159274523258039945703196915552803357060194210277781675586997054440658404009267452412917310117764963744386822500490196206238198755490392641326959038568460210313399742686750309925621301250654757279382644685538617136012388205214170331552046378619375187213218171997417106331879416206786715812384426341938352831526322783429635724051054998211772757927151582484693647690768815728965642784318969373306348110280643220349578326483111376892842591935116145292145590152852012916992897077437465612574906825047885428429869201490722837581639004686697932689897571152446994595741837793462410490578943937659509151923560335566254594650248623211922238145965455261658540636353037873207137624061646770512252776762872"))
        {
            printf("Test intal_multiply_7 PASSED\n");
        }
        else
        {
            printf("Test intal_multiply_7 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "152415787806736785159274523258039945703196915552803357060194210277781675586997054440658404009267452412917310117764963744386822500490196206238198755490392641326959038568460210313399742686750309925621301250654757279382644685538617136012388205214170331552046378619375187213218171997417106331879416206786715812384426341938352831526322783429635724051054998211772757927151582484693647690768815728965642784318969373306348110280643220349578326483111376892842591935116145292145590152852012916992897077437465612574906825047885428429869201490722837581639004686697932689897571152446994595741837793462410490578943937659509151923560335566254594650248623211922238145965455261658540636353037873207137624061646770512252776762872");
        }
        free(result1);
    }

    result1 = intal_mod(a[3], a[4]);
    if (!result1)
    {
        printf("Test intal_mod FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1"))
        {
            printf("Test intal_mod_1 PASSED\n");
        }
        else
        {
            printf("Test intal_mod_1 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
        }
        free(result1);
    }

    result1 = intal_mod("978", "5");
    if (!result1)
    {
        printf("Test intal_mod_2 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "3"))
        {
            printf("Test intal_mod_2 PASSED\n");
        }
        else
        {
            printf("Test intal_mod_2 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
        }
        free(result1);
    }

    result1 = intal_mod(a[0], a[5]);
    if (!result1)
    {
        printf("Test intal_mod_3 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "9"))
        {
            printf("Test intal_mod_3 PASSED\n");
        }
        else
        {
            printf("Test intal_mod_3 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "9");
        }
        free(result1);
    }

    result1 = intal_mod("1234567", "1234");
    if (!result1)
    {
        printf("Test intal_mod_4 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "567"))
        {
            printf("Test intal_mod_4 PASSED\n");
        }
        else
        {
            printf("Test intal_mod_4 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "567");
        }
        free(result1);
    }

    result1 = intal_mod("5485743258475748273548732587432875758942375847235847254890723854702385784293753827584732895748325740827584676715489257425674892674875894705273485678436561874817584738758784371584310758439170584319758347584758947158974875476485740175841074328975843105748137458467843975843107510578417185748375483290758436584375846510896584375817408134798574893257684362547632578461759674863157647561095640509415674615750157647831561756413756843156138096784397584310751057841718574837548329075843658437584651089658437581740813479857489325768436254763257846175967486315764756109564050548732052089754892768297350823750843275894078328597438297510574328975448936789321573980127501937875892750832475481390759831257381927589378203", "76843625476325784617596748631576475610956405054873205208975489276829735082375084327589407832859743829751057432897544893678932157398012750193787589275083247548139075983125738192758937452375874329587432856472365743627523945432015367564327854647320564732564736573248");
    if (!result1)
    {
        printf("Test intal_mod_5 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "6745592845074042758050336179214847982127235696391047009999027698134925987445509261599801651598156933137843371719215878285029944889346142501291925415531320146024800732959059576926722380013672792040484448841650176640673892922708805408958509189858278475560819015643"))
        {
            printf("Test intal_mod_5 PASSED\n");
        }
        else
        {
            printf("Test intal_mod_5 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "6745592845074042758050336179214847982127235696391047009999027698134925987445509261599801651598156933137843371719215878285029944889346142501291925415531320146024800732959059576926722380013672792040484448841650176640673892922708805408958509189858278475560819015643");
        }
        free(result1);
    }

    result1 = intal_mod("6009718283015176403663795566576162662464392508574732941892493378041287514785490833290011771831023295650730983904674317780533596511338830921574689273378260858510780461747635304608137045625978727076105306422669766735981164515011936314096594414739987445187310176993669314314964134007344171542300672775810841964238891541657509117150496836946844114930798244740186355174352591724321844226307473471633111564484525960497912538742028313025808319681120703327146943820081525237635998446839386440504318735424468939868357332052065251532472477819395238944974576414", "6009718283015176403663795566576162662464392508574732941892493378041287514785490833290011771831023295650730983904674317780533596511338830921574689273378260858510780461747635304608137045625978727076105306422669766735981164515011936314096594414739987445187310176993669314314964134007344171542300672775810841964238891541657509117150496836946844114930798244740186355174352591724321844226307473471633111564484525960497912538742028313025808319681120703327146943820081525237635998446839386440504318735424468939868357332052065251532472477819395238944974576413");
    if (!result1)
    {
        printf("Test intal_mod_6 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1"))
        {
            printf("Test intal_mod_6 PASSED\n");
        }
        else
        {
            printf("Test intal_mod_6 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
        }
        free(result1);
    }

    result1 = intal_mod("6009718283015176403663795566576162662464392508574732941892493378041287514785490833290011771831023295650730983904674317780533596511338830921574689273378260858510780461747635304608137045625978727076105306422669766735981164515011936314096594414739987445187310176993669314314964134007344171542300672775810841964238891541657509117150496836946844114930798244740186355174352591724321844226307473471633111564484525960497912538742028313025808319681120703327146943820081525237635998446839386440504318735424468939868357332052065251532472477819395238944974576414", "851457738490115330496856019885585547977839353822534124001452912230164800019467638992996780635565264875318455557467554474764266427665976814971726869656936371726796750224827751260264100035352425423630095656802839858528799580950581376188196977942314429339704728055099253612779801730757516118464551523745168150695620712096608555754987213481690238010117060609817608520527229329170458801908015725600351203577140180813557162570011698967535492904308361085234");
    if (!result1)
    {
        printf("Test intal_mod_7 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "557196485155210447468653532986956266423245339204105209975735972590578924255878297423697774687459663145639442528034537640383976602046413334972307317600690136157605738124427440517297859032360615886031802304837695125246259372537190749784406983714564143313034510364088966063481797882556223564955662428995774049973200891170627308515643909146839490730105676425064939546211630474466761579571658305242599574893495381928015546272649775788688254695736647958550"))
        {
            printf("Test intal_mod_7 PASSED\n");
        }
        else
        {
            printf("Test intal_mod_7 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "557196485155210447468653532986956266423245339204105209975735972590578924255878297423697774687459663145639442528034537640383976602046413334972307317600690136157605738124427440517297859032360615886031802304837695125246259372537190749784406983714564143313034510364088966063481797882556223564955662428995774049973200891170627308515643909146839490730105676425064939546211630474466761579571658305242599574893495381928015546272649775788688254695736647958550");
        }
        free(result1);
    }

    result1 = intal_pow(a[5], 3);
    if (!result1)
    {
        printf("Test intal_pow FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1728"))
        {
            printf("Test intal_pow PASSED\n");
        }
        else
        {
            printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1728");
        }
        free(result1);
    }

    result1 = intal_pow("10", 999);
    if (!result1)
    {
        printf("Test intal_pow FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, a[10]))
        {
            printf("Test intal_pow PASSED\n");
        }
        else
        {
            printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[10]);
        }
        free(result1);
    }

    result1 = intal_pow("2", 3000);
    if (!result1)
    {
        printf("Test intal_pow FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, a[11]))
        {
            printf("Test intal_pow PASSED\n");
        }
        else
        {
            printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[11]);
        }
        free(result1);
    }

    result1 = intal_gcd(a[0], a[5]);
    if (!result1)
    {
        printf("Test intal_gcd FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "3"))
        {
            printf("Test intal_gcd_1 PASSED\n");
        }
        else
        {
            printf("Test intal_gcd_1 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
        }
        free(result1);
    }

    result1 = intal_gcd("6009718283015176403663795566576162662464392508574732941892493378041287514785490833290011771831023295650730983904674317780533596511338830921574689273378260858510780461747635304608137045625978727076105306422669766735981164515011936314096594414739987445187310176993669314314964134007344171542300672775810841964238891541657509117150496836946844114930798244740186355174352591724321844226307473471633111564484525960497912538742028313025808319681120703327146943820081525237635998446839386440504318735424468939868357332052065251532472477819395238944974576414", "851457738490115330496856019885585547977839353822534124001452912230164800019467638992996780635565264875318455557467554474764266427665976814971726869656936371726796750224827751260264100035352425423630095656802839858528799580950581376188196977942314429339704728055099253612779801730757516118464551523745168150695620712096608555754987213481690238010117060609817608520527229329170458801908015725600351203577140180813557162570011698967535492904308361085234");
    if (!result1)
    {
        printf("Test intal_gcd_2 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "2"))
        {
            printf("Test intal_gcd_2 PASSED\n");
        }
        else
        {
            printf("Test intal_gcd_2 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2");
        }
        free(result1);
    }

    result1 = intal_gcd("17", "29");
    if (!result1)
    {
        printf("Test intal_gcd_3 FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "1"))
        {
            printf("Test intal_gcd_3 PASSED\n");
        }
        else
        {
            printf("Test intal_gcd_3 FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
        }
        free(result1);
    }

    result1 = intal_fibonacci(3);
    if (!result1)
    {
        printf("Test intal_fibonacci FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "2"))
        {
            printf("Test intal_fibonacci PASSED\n");
        }
        else
        {
            printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2");
        }
        free(result1);
    }

    result1 = intal_fibonacci(1000);
    if (!result1)
    {
        printf("Test intal_fibonacci FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875"))
        {
            printf("Test intal_fibonacci PASSED\n");
        }
        else
        {
            printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
        }
        free(result1);
    }

    result1 = intal_factorial(30);
    if (!result1)
    {
        printf("Test intal_factorial FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, a[6]))
        {
            printf("Test intal_factorial PASSED\n");
        }
        else
        {
            printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
        }
        free(result1);
    }

    result1 = intal_factorial(100);
    if (!result1)
    {
        printf("Test intal_factorial FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000"))
        {
            printf("Test intal_factorial PASSED\n");
        }
        else
        {
            printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
        }
        free(result1);
    }
    
    result1 = intal_factorial(200);
    if (!result1)
    {
        printf("Test intal_factorial FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "788657867364790503552363213932185062295135977687173263294742533244359449963403342920304284011984623904177212138919638830257642790242637105061926624952829931113462857270763317237396988943922445621451664240254033291864131227428294853277524242407573903240321257405579568660226031904170324062351700858796178922222789623703897374720000000000000000000000000000000000000000000000000"))
        {
            printf("Test intal_factorial PASSED\n");
        }
        else
        {
            printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "788657867364790503552363213932185062295135977687173263294742533244359449963403342920304284011984623904177212138919638830257642790242637105061926624952829931113462857270763317237396988943922445621451664240254033291864131227428294853277524242407573903240321257405579568660226031904170324062351700858796178922222789623703897374720000000000000000000000000000000000000000000000000");
        }
        free(result1);
    }

    
    result1 = intal_bincoeff(10, 8);
    if (!result1)
    {
        printf("Test intal_bincoeff FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "45"))
        {
            printf("Test intal_bincoeff PASSED\n");
        }
        else
        {
            printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "45");
        }
        free(result1);
    }

    result1 = intal_bincoeff(1000, 900);
    if (!result1)
    {
        printf("Test intal_bincoeff FAILED.\n");
    }
    else
    {
        if (0 == strcmp(result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890"))
        {
            printf("Test intal_bincoeff PASSED\n");
        }
        else
        {
            printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890");
        }
        free(result1);
    }

    index1 = intal_max(a, n);
    if (10 == index1)
    {
        printf("Test intal_max PASSED\n");
    }
    else
    {
        printf("Test intal_max FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
    }

    index1 = intal_min(a, n);
    if (2 == index1)
    {
        printf("Test intal_min PASSED\n");
    }
    else
    {
        printf("Test intal_min FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 2);
    }

    index1 = intal_search(a, n, a[7]);
    if (6 == index1)
    {
        printf("Test intal_search_1 PASSED\n");
    }
    else
    {
        printf("Test intal_search_1 FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
    }

    index1 = intal_search(a, n, "1");
    if (-1 == index1)
    {
        printf("Test intal_search_2 PASSED\n");
    }
    else
    {
        printf("Test intal_search_2 FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
    }

    result1 = coin_row_problem(a, n);
    if (!result1)
    {
        printf("Test coin_row_problem FAILED.\n");
    }
    else
    {
        if (0 == strcmp("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987", result1))
        {
            printf("Test coin_row_problem PASSED\n");
        }
        else
        {
            printf("Test coin_row_problem FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987");
        }
        free(result1);
    }

    intal_sort(a, n);
    printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", a[i]);
    }
    printf("\n");

    index1 = intal_binsearch(a, n, "3");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%s\n", a[i]);
    // }
    printf("\n");
    if (1 == index1)
    {
        printf("Test intal_binsearch and probably intal_sort PASSED\n");
    }
    else
    {
        printf("Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 1);
    }

    index1 = intal_binsearch(a, n, "1");
    if (-1 == index1)
    {
        printf("Test intal_binsearch_1 PASSED\n");
    }
    else
    {
        printf("Test intal_binsearch_1 FAILED\nYour answer: %d\nExpected answer: %d\n", index1, -1);
    }

    // Don't forget to free all the memory that is dynamically allocated.
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
   /* */return 0;
}
