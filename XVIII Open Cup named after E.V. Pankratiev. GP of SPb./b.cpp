#include <stdio.h>
#include <math.h>
long long n;
int f[65][65];

/*int popcount(long long b)
{
  b = (b & 0x5555555555555555LU) + (b >> 1 & 0x5555555555555555LU);
  b = (b & 0x3333333333333333LU) + (b >> 2 & 0x3333333333333333LU);
  b = b + (b >> 4) & 0x0F0F0F0F0F0F0F0FLU;
  b = b + (b >> 8);
  b = b + (b >> 16);
  b = b + (b >> 32) & 0x0000007F;
  return (int) b;
} */
int main(){
f[1][1]=1;
f[1][3]=1;
f[1][5]=1;
f[1][7]=1;
f[1][9]=1;
f[1][11]=1;
f[1][13]=1;
f[1][15]=1;
f[1][17]=1;
f[1][19]=1;
f[1][21]=1;
f[1][23]=1;
f[1][25]=1;
f[1][27]=1;
f[1][29]=1;
f[1][31]=1;
f[1][33]=1;
f[1][35]=1;
f[1][37]=1;
f[1][39]=1;
f[1][41]=1;
f[1][43]=1;
f[1][45]=1;
f[1][47]=1;
f[1][49]=1;
f[1][51]=1;
f[1][53]=1;
f[1][55]=1;
f[1][57]=1;
f[1][59]=1;
f[2][4]=1;
f[2][6]=1;
f[2][8]=1;
f[2][10]=1;
f[2][12]=1;
f[2][14]=1;
f[2][16]=1;
f[2][18]=1;
f[2][20]=1;
f[2][22]=1;
f[2][24]=1;
f[2][26]=1;
f[2][28]=1;
f[2][30]=1;
f[2][32]=1;
f[2][34]=1;
f[2][36]=1;
f[2][38]=1;
f[2][40]=1;
f[2][42]=1;
f[2][44]=1;
f[2][46]=1;
f[2][48]=1;
f[2][50]=1;
f[2][52]=1;
f[2][54]=1;
f[2][56]=1;
f[2][58]=1;
f[2][60]=1;
f[3][5]=1;
f[3][6]=1;
f[3][7]=2;
f[3][8]=1;
f[3][9]=3;
f[3][10]=2;
f[3][11]=4;
f[3][12]=2;
f[3][13]=5;
f[3][14]=2;
f[3][15]=6;
f[3][16]=2;
f[3][17]=7;
f[3][18]=2;
f[3][19]=8;
f[3][20]=2;
f[3][21]=9;
f[3][22]=2;
f[3][23]=10;
f[3][24]=2;
f[3][25]=11;
f[3][26]=2;
f[3][27]=12;
f[3][28]=2;
f[3][29]=13;
f[3][30]=2;
f[3][31]=14;
f[3][32]=2;
f[3][33]=15;
f[3][34]=2;
f[3][35]=16;
f[3][36]=2;
f[3][37]=17;
f[3][38]=2;
f[3][39]=18;
f[3][40]=2;
f[3][41]=19;
f[3][42]=2;
f[3][43]=20;
f[3][44]=2;
f[3][45]=21;
f[3][46]=2;
f[3][47]=22;
f[3][48]=2;
f[3][49]=23;
f[3][50]=2;
f[3][51]=24;
f[3][52]=2;
f[3][53]=25;
f[3][54]=2;
f[3][55]=26;
f[3][56]=2;
f[3][57]=27;
f[3][58]=2;
f[3][59]=28;
f[3][60]=2;
f[4][8]=2;
f[4][10]=2;
f[4][12]=3;
f[4][14]=4;
f[4][16]=4;
f[4][18]=4;
f[4][20]=4;
f[4][22]=4;
f[4][24]=4;
f[4][26]=4;
f[4][28]=4;
f[4][30]=4;
f[4][32]=4;
f[4][34]=4;
f[4][36]=4;
f[4][38]=4;
f[4][40]=4;
f[4][42]=4;
f[4][44]=4;
f[4][46]=4;
f[4][48]=4;
f[4][50]=4;
f[4][52]=4;
f[4][54]=4;
f[4][56]=4;
f[4][58]=4;
f[4][60]=3;
f[5][7]=1;
f[5][9]=2;
f[5][10]=3;
f[5][11]=4;
f[5][12]=5;
f[5][13]=6;
f[5][14]=8;
f[5][15]=9;
f[5][16]=10;
f[5][17]=11;
f[5][18]=12;
f[5][19]=13;
f[5][20]=14;
f[5][21]=14;
f[5][22]=16;
f[5][23]=16;
f[5][24]=17;
f[5][25]=17;
f[5][26]=19;
f[5][27]=19;
f[5][28]=20;
f[5][29]=20;
f[5][30]=21;
f[5][31]=22;
f[5][32]=22;
f[5][33]=23;
f[5][34]=23;
f[5][35]=25;
f[5][36]=24;
f[5][37]=26;
f[5][38]=25;
f[5][39]=28;
f[5][40]=26;
f[5][41]=29;
f[5][42]=27;
f[5][43]=31;
f[5][44]=28;
f[5][45]=32;
f[5][46]=29;
f[5][47]=34;
f[5][48]=30;
f[5][49]=35;
f[5][50]=31;
f[5][51]=37;
f[5][52]=32;
f[5][53]=38;
f[5][54]=33;
f[5][55]=40;
f[5][56]=34;
f[5][57]=41;
f[5][58]=35;
f[5][59]=43;
f[5][60]=34;
f[6][9]=1;
f[6][10]=1;
f[6][11]=2;
f[6][12]=4;
f[6][13]=5;
f[6][14]=7;
f[6][15]=10;
f[6][16]=13;
f[6][17]=17;
f[6][18]=18;
f[6][19]=23;
f[6][20]=21;
f[6][21]=32;
f[6][22]=25;
f[6][23]=39;
f[6][24]=27;
f[6][25]=51;
f[6][26]=29;
f[6][27]=60;
f[6][28]=30;
f[6][29]=71;
f[6][30]=32;
f[6][31]=82;
f[6][32]=35;
f[6][33]=95;
f[6][34]=36;
f[6][35]=108;
f[6][36]=38;
f[6][37]=123;
f[6][38]=39;
f[6][39]=138;
f[6][40]=40;
f[6][41]=155;
f[6][42]=41;
f[6][43]=172;
f[6][44]=43;
f[6][45]=191;
f[6][46]=44;
f[6][47]=210;
f[6][48]=45;
f[6][49]=231;
f[6][50]=46;
f[6][51]=252;
f[6][52]=47;
f[6][53]=275;
f[6][54]=48;
f[6][55]=298;
f[6][56]=49;
f[6][57]=323;
f[6][58]=50;
f[6][59]=348;
f[6][60]=47;
f[7][11]=2;
f[7][12]=2;
f[7][13]=6;
f[7][14]=7;
f[7][15]=8;
f[7][16]=14;
f[7][17]=13;
f[7][18]=24;
f[7][19]=18;
f[7][20]=32;
f[7][21]=26;
f[7][22]=41;
f[7][23]=33;
f[7][24]=47;
f[7][25]=37;
f[7][26]=55;
f[7][27]=43;
f[7][28]=58;
f[7][29]=47;
f[7][30]=61;
f[7][31]=50;
f[7][32]=63;
f[7][33]=52;
f[7][34]=66;
f[7][35]=55;
f[7][36]=67;
f[7][37]=57;
f[7][38]=70;
f[7][39]=59;
f[7][40]=71;
f[7][41]=60;
f[7][42]=73;
f[7][43]=62;
f[7][44]=75;
f[7][45]=64;
f[7][46]=77;
f[7][47]=66;
f[7][48]=78;
f[7][49]=67;
f[7][50]=80;
f[7][51]=69;
f[7][52]=81;
f[7][53]=71;
f[7][54]=83;
f[7][55]=73;
f[7][56]=84;
f[7][57]=74;
f[7][58]=86;
f[7][59]=76;
f[7][60]=78;
f[8][11]=1;
f[8][12]=1;
f[8][13]=2;
f[8][14]=6;
f[8][15]=6;
f[8][16]=14;
f[8][17]=14;
f[8][18]=29;
f[8][19]=26;
f[8][20]=48;
f[8][21]=42;
f[8][22]=73;
f[8][23]=58;
f[8][24]=99;
f[8][25]=75;
f[8][26]=122;
f[8][27]=90;
f[8][28]=150;
f[8][29]=107;
f[8][30]=175;
f[8][31]=119;
f[8][32]=200;
f[8][33]=130;
f[8][34]=213;
f[8][35]=140;
f[8][36]=228;
f[8][37]=149;
f[8][38]=237;
f[8][39]=154;
f[8][40]=249;
f[8][41]=163;
f[8][42]=259;
f[8][43]=169;
f[8][44]=266;
f[8][45]=177;
f[8][46]=275;
f[8][47]=184;
f[8][48]=283;
f[8][49]=191;
f[8][50]=290;
f[8][51]=196;
f[8][52]=298;
f[8][53]=202;
f[8][54]=305;
f[8][55]=207;
f[8][56]=312;
f[8][57]=214;
f[8][58]=318;
f[8][59]=219;
f[8][60]=302;
f[9][13]=2;
f[9][14]=2;
f[9][15]=12;
f[9][16]=9;
f[9][17]=28;
f[9][18]=23;
f[9][19]=59;
f[9][20]=56;
f[9][21]=97;
f[9][22]=88;
f[9][23]=150;
f[9][24]=141;
f[9][25]=202;
f[9][26]=213;
f[9][27]=261;
f[9][28]=263;
f[9][29]=321;
f[9][30]=323;
f[9][31]=399;
f[9][32]=372;
f[9][33]=469;
f[9][34]=428;
f[9][35]=544;
f[9][36]=470;
f[9][37]=606;
f[9][38]=510;
f[9][39]=683;
f[9][40]=552;
f[9][41]=752;
f[9][42]=586;
f[9][43]=832;
f[9][44]=621;
f[9][45]=896;
f[9][46]=652;
f[9][47]=980;
f[9][48]=682;
f[9][49]=1049;
f[9][50]=713;
f[9][51]=1143;
f[9][52]=745;
f[9][53]=1217;
f[9][54]=777;
f[9][55]=1318;
f[9][56]=809;
f[9][57]=1400;
f[9][58]=841;
f[9][59]=1509;
f[9][60]=812;
f[10][15]=1;
f[10][16]=5;
f[10][17]=9;
f[10][18]=18;
f[10][19]=26;
f[10][20]=47;
f[10][21]=58;
f[10][22]=101;
f[10][23]=108;
f[10][24]=169;
f[10][25]=185;
f[10][26]=250;
f[10][27]=292;
f[10][28]=370;
f[10][29]=397;
f[10][30]=480;
f[10][31]=499;
f[10][32]=591;
f[10][33]=634;
f[10][34]=693;
f[10][35]=772;
f[10][36]=789;
f[10][37]=918;
f[10][38]=880;
f[10][39]=1049;
f[10][40]=964;
f[10][41]=1201;
f[10][42]=1039;
f[10][43]=1345;
f[10][44]=1099;
f[10][45]=1509;
f[10][46]=1152;
f[10][47]=1678;
f[10][48]=1193;
f[10][49]=1870;
f[10][50]=1229;
f[10][51]=2056;
f[10][52]=1259;
f[10][53]=2272;
f[10][54]=1289;
f[10][55]=2497;
f[10][56]=1315;
f[10][57]=2755;
f[10][58]=1343;
f[10][59]=3017;
f[10][60]=1217;
f[11][16]=2;
f[11][17]=4;
f[11][18]=13;
f[11][19]=19;
f[11][20]=36;
f[11][21]=54;
f[11][22]=94;
f[11][23]=124;
f[11][24]=201;
f[11][25]=248;
f[11][26]=329;
f[11][27]=386;
f[11][28]=503;
f[11][29]=602;
f[11][30]=729;
f[11][31]=825;
f[11][32]=1006;
f[11][33]=1055;
f[11][34]=1277;
f[11][35]=1295;
f[11][36]=1568;
f[11][37]=1535;
f[11][38]=1844;
f[11][39]=1761;
f[11][40]=2116;
f[11][41]=1972;
f[11][42]=2333;
f[11][43]=2161;
f[11][44]=2531;
f[11][45]=2333;
f[11][46]=2716;
f[11][47]=2473;
f[11][48]=2898;
f[11][49]=2595;
f[11][50]=3052;
f[11][51]=2710;
f[11][52]=3191;
f[11][53]=2806;
f[11][54]=3306;
f[11][55]=2899;
f[11][56]=3412;
f[11][57]=2979;
f[11][58]=3515;
f[11][59]=3052;
f[11][60]=3272;
f[12][17]=2;
f[12][18]=5;
f[12][19]=9;
f[12][20]=23;
f[12][21]=40;
f[12][22]=72;
f[12][23]=116;
f[12][24]=168;
f[12][25]=259;
f[12][26]=374;
f[12][27]=490;
f[12][28]=657;
f[12][29]=812;
f[12][30]=1069;
f[12][31]=1229;
f[12][32]=1540;
f[12][33]=1718;
f[12][34]=2105;
f[12][35]=2241;
f[12][36]=2691;
f[12][37]=2775;
f[12][38]=3362;
f[12][39]=3372;
f[12][40]=3973;
f[12][41]=3934;
f[12][42]=4584;
f[12][43]=4501;
f[12][44]=5205;
f[12][45]=5023;
f[12][46]=5718;
f[12][47]=5473;
f[12][48]=6148;
f[12][49]=5919;
f[12][50]=6558;
f[12][51]=6308;
f[12][52]=6901;
f[12][53]=6672;
f[12][54]=7225;
f[12][55]=6990;
f[12][56]=7479;
f[12][57]=7305;
f[12][58]=7736;
f[12][59]=7608;
f[12][60]=7245;
f[13][15]=1;
f[13][17]=1;
f[13][19]=9;
f[13][20]=8;
f[13][21]=35;
f[13][22]=43;
f[13][23]=107;
f[13][24]=128;
f[13][25]=255;
f[13][26]=321;
f[13][27]=564;
f[13][28]=701;
f[13][29]=1035;
f[13][30]=1213;
f[13][31]=1751;
f[13][32]=1977;
f[13][33]=2661;
f[13][34]=2979;
f[13][35]=3779;
f[13][36]=4207;
f[13][37]=5062;
f[13][38]=5487;
f[13][39]=6440;
f[13][40]=6923;
f[13][41]=7893;
f[13][42]=8408;
f[13][43]=9392;
f[13][44]=9816;
f[13][45]=10830;
f[13][46]=11105;
f[13][47]=12223;
f[13][48]=12402;
f[13][49]=13525;
f[13][50]=13475;
f[13][51]=14754;
f[13][52]=14495;
f[13][53]=15866;
f[13][54]=15354;
f[13][55]=16886;
f[13][56]=16103;
f[13][57]=17848;
f[13][58]=16726;
f[13][59]=18753;
f[13][60]=15712;
f[14][19]=2;
f[14][20]=5;
f[14][21]=14;
f[14][22]=22;
f[14][23]=52;
f[14][24]=103;
f[14][25]=173;
f[14][26]=283;
f[14][27]=433;
f[14][28]=685;
f[14][29]=951;
f[14][30]=1427;
f[14][31]=1856;
f[14][32]=2506;
f[14][33]=3235;
f[14][34]=4116;
f[14][35]=5120;
f[14][36]=6248;
f[14][37]=7484;
f[14][38]=8840;
f[14][39]=10342;
f[14][40]=11777;
f[14][41]=13479;
f[14][42]=15027;
f[14][43]=16828;
f[14][44]=18406;
f[14][45]=20309;
f[14][46]=21855;
f[14][47]=23928;
f[14][48]=25307;
f[14][49]=27444;
f[14][50]=28460;
f[14][51]=30989;
f[14][52]=31434;
f[14][53]=34337;
f[14][54]=34073;
f[14][55]=37512;
f[14][56]=36456;
f[14][57]=40560;
f[14][58]=38521;
f[14][59]=43532;
f[14][60]=37013;
f[15][20]=2;
f[15][21]=2;
f[15][22]=12;
f[15][23]=24;
f[15][24]=59;
f[15][25]=102;
f[15][26]=200;
f[15][27]=330;
f[15][28]=523;
f[15][29]=865;
f[15][30]=1270;
f[15][31]=1851;
f[15][32]=2716;
f[15][33]=3631;
f[15][34]=4873;
f[15][35]=6288;
f[15][36]=8076;
f[15][37]=10063;
f[15][38]=12402;
f[15][39]=14794;
f[15][40]=17839;
f[15][41]=20706;
f[15][42]=24203;
f[15][43]=27411;
f[15][44]=31342;
f[15][45]=34926;
f[15][46]=39092;
f[15][47]=42780;
f[15][48]=47032;
f[15][49]=50839;
f[15][50]=55138;
f[15][51]=58772;
f[15][52]=62616;
f[15][53]=66474;
f[15][54]=69746;
f[15][55]=73896;
f[15][56]=76409;
f[15][57]=80870;
f[15][58]=82428;
f[15][59]=87217;
f[15][60]=79895;
f[16][21]=1;
f[16][22]=5;
f[16][23]=7;
f[16][24]=22;
f[16][25]=46;
f[16][26]=123;
f[16][27]=200;
f[16][28]=401;
f[16][29]=624;
f[16][30]=1052;
f[16][31]=1582;
f[16][32]=2497;
f[16][33]=3472;
f[16][34]=5173;
f[16][35]=6733;
f[16][36]=9292;
f[16][37]=11941;
f[16][38]=15713;
f[16][39]=19291;
f[16][40]=24419;
f[16][41]=29076;
f[16][42]=35657;
f[16][43]=41085;
f[16][44]=49148;
f[16][45]=55332;
f[16][46]=64799;
f[16][47]=71104;
f[16][48]=81491;
f[16][49]=88248;
f[16][50]=99528;
f[16][51]=105749;
f[16][52]=117903;
f[16][53]=123450;
f[16][54]=136044;
f[16][55]=140311;
f[16][56]=153081;
f[16][57]=156496;
f[16][58]=169220;
f[16][59]=171443;
f[16][60]=167875;
f[17][23]=4;
f[17][24]=10;
f[17][25]=24;
f[17][26]=55;
f[17][27]=121;
f[17][28]=237;
f[17][29]=455;
f[17][30]=774;
f[17][31]=1388;
f[17][32]=2054;
f[17][33]=3405;
f[17][34]=4835;
f[17][35]=7345;
f[17][36]=10062;
f[17][37]=13993;
f[17][38]=18508;
f[17][39]=24574;
f[17][40]=31161;
f[17][41]=39624;
f[17][42]=48980;
f[17][43]=60172;
f[17][44]=72276;
f[17][45]=86259;
f[17][46]=101109;
f[17][47]=117295;
f[17][48]=135109;
f[17][49]=152754;
f[17][50]=173252;
f[17][51]=191727;
f[17][52]=214138;
f[17][53]=232776;
f[17][54]=256877;
f[17][55]=275338;
f[17][56]=299842;
f[17][57]=317488;
f[17][58]=342114;
f[17][59]=358520;
f[17][60]=346736;
f[18][24]=1;
f[18][25]=9;
f[18][26]=12;
f[18][27]=62;
f[18][28]=114;
f[18][29]=267;
f[18][30]=494;
f[18][31]=893;
f[18][32]=1520;
f[18][33]=2493;
f[18][34]=4082;
f[18][35]=6286;
f[18][36]=9441;
f[18][37]=13622;
f[18][38]=19225;
f[18][39]=26678;
f[18][40]=35769;
f[18][41]=47624;
f[18][42]=61370;
f[18][43]=78231;
f[18][44]=97566;
f[18][45]=120262;
f[18][46]=145815;
f[18][47]=174975;
f[18][48]=206681;
f[18][49]=241736;
f[18][50]=279494;
f[18][51]=319951;
f[18][52]=362948;
f[18][53]=407879;
f[18][54]=454500;
f[18][55]=502678;
f[18][56]=552282;
f[18][57]=601588;
f[18][58]=651659;
f[18][59]=701897;
f[18][60]=678366;
f[19][25]=2;
f[19][26]=5;
f[19][27]=21;
f[19][28]=60;
f[19][29]=123;
f[19][30]=284;
f[19][31]=572;
f[19][32]=1066;
f[19][33]=1899;
f[19][34]=3121;
f[19][35]=5259;
f[19][36]=8195;
f[19][37]=12737;
f[19][38]=18704;
f[19][39]=27352;
f[19][40]=38168;
f[19][41]=52997;
f[19][42]=70776;
f[19][43]=94408;
f[19][44]=121866;
f[19][45]=156256;
f[19][46]=195273;
f[19][47]=242480;
f[19][48]=294599;
f[19][49]=355727;
f[19][50]=421721;
f[19][51]=498003;
f[19][52]=576879;
f[19][53]=667037;
f[19][54]=758480;
f[19][55]=860560;
f[19][56]=962617;
f[19][57]=1073789;
f[19][58]=1182778;
f[19][59]=1300233;
f[19][60]=1266558;
f[20][26]=2;
f[20][27]=8;
f[20][28]=13;
f[20][29]=49;
f[20][30]=133;
f[20][31]=243;
f[20][32]=579;
f[20][33]=1108;
f[20][34]=2091;
f[20][35]=3578;
f[20][36]=6116;
f[20][37]=10066;
f[20][38]=15759;
f[20][39]=24125;
f[20][40]=36233;
f[20][41]=51977;
f[20][42]=73917;
f[20][43]=102051;
f[20][44]=138034;
f[20][45]=183102;
f[20][46]=238707;
f[20][47]=305890;
f[20][48]=387150;
f[20][49]=480922;
f[20][50]=590808;
f[20][51]=714780;
f[20][52]=856768;
f[20][53]=1013167;
f[20][54]=1187684;
f[20][55]=1374224;
f[20][56]=1580376;
f[20][57]=1795058;
f[20][58]=2028882;
f[20][59]=2267232;
f[20][60]=2241078;
f[21][27]=1;
f[21][28]=4;
f[21][29]=21;
f[21][30]=36;
f[21][31]=139;
f[21][32]=283;
f[21][33]=611;
f[21][34]=1262;
f[21][35]=2331;
f[21][36]=4283;
f[21][37]=7451;
f[21][38]=12511;
f[21][39]=20238;
f[21][40]=31516;
f[21][41]=48370;
f[21][42]=71166;
f[21][43]=103375;
f[21][44]=145259;
f[21][45]=201412;
f[21][46]=272301;
f[21][47]=363024;
f[21][48]=473481;
f[21][49]=610971;
f[21][50]=772602;
f[21][51]=967286;
f[21][52]=1189558;
f[21][53]=1449930;
f[21][54]=1742791;
f[21][55]=2073140;
f[21][56]=2439281;
f[21][57]=2842655;
f[21][58]=3283152;
f[21][59]=3754350;
f[21][60]=3748388;
f[22][28]=2;
f[22][29]=5;
f[22][30]=10;
f[22][31]=50;
f[22][32]=106;
f[22][33]=270;
f[22][34]=566;
f[22][35]=1261;
f[22][36]=2540;
f[22][37]=4650;
f[22][38]=8640;
f[22][39]=14560;
f[22][40]=24602;
f[22][41]=39308;
f[22][42]=61695;
f[22][43]=93040;
f[22][44]=138908;
f[22][45]=199383;
f[22][46]=283526;
f[22][47]=390899;
f[22][48]=533212;
f[22][49]=709932;
f[22][50]=932349;
f[22][51]=1202134;
f[22][52]=1533361;
f[22][53]=1920436;
f[22][54]=2382318;
f[22][55]=2910576;
f[22][56]=3525357;
f[22][57]=4208837;
f[22][58]=4989866;
f[22][59]=5835554;
f[22][60]=5903943;
f[23][29]=1;
f[23][30]=6;
f[23][31]=6;
f[23][32]=39;
f[23][33]=114;
f[23][34]=304;
f[23][35]=654;
f[23][36]=1411;
f[23][37]=2798;
f[23][38]=5448;
f[23][39]=9929;
f[23][40]=17636;
f[23][41]=29568;
f[23][42]=49246;
f[23][43]=78390;
f[23][44]=121820;
f[23][45]=184745;
f[23][46]=272208;
f[23][47]=393949;
f[23][48]=555142;
f[23][49]=770732;
f[23][50]=1048116;
f[23][51]=1401515;
f[23][52]=1843149;
f[23][53]=2389245;
f[23][54]=3050538;
f[23][55]=3847818;
f[23][56]=4781004;
f[23][57]=5880830;
f[23][58]=7141238;
f[23][59]=8586426;
f[23][60]=8760872;
f[24][30]=1;
f[24][31]=1;
f[24][32]=14;
f[24][33]=39;
f[24][34]=100;
f[24][35]=302;
f[24][36]=639;
f[24][37]=1459;
f[24][38]=2955;
f[24][39]=5918;
f[24][40]=11094;
f[24][41]=20318;
f[24][42]=35210;
f[24][43]=59373;
f[24][44]=97347;
f[24][45]=154720;
f[24][46]=239578;
f[24][47]=361662;
f[24][48]=533192;
f[24][49]=768658;
f[24][50]=1088643;
f[24][51]=1509519;
f[24][52]=2058333;
f[24][53]=2757319;
f[24][54]=3640762;
f[24][55]=4726771;
f[24][56]=6063106;
f[24][57]=7663771;
f[24][58]=9579057;
f[24][59]=11813396;
f[24][60]=12206114;
f[25][31]=1;
f[25][32]=2;
f[25][33]=14;
f[25][34]=30;
f[25][35]=116;
f[25][36]=259;
f[25][37]=669;
f[25][38]=1419;
f[25][39]=3245;
f[25][40]=6341;
f[25][41]=12570;
f[25][42]=23147;
f[25][43]=42003;
f[25][44]=71258;
f[25][45]=120321;
f[25][46]=193853;
f[25][47]=308987;
f[25][48]=473502;
f[25][49]=714208;
f[25][50]=1048679;
f[25][51]=1514507;
f[25][52]=2138082;
f[25][53]=2973365;
f[25][54]=4049178;
f[25][55]=5446027;
f[25][56]=7191681;
f[25][57]=9386973;
f[25][58]=12049803;
f[25][59]=15318198;
f[25][60]=15974874;
f[26][33]=2;
f[26][34]=9;
f[26][35]=38;
f[26][36]=91;
f[26][37]=259;
f[26][38]=638;
f[26][39]=1437;
f[26][40]=3249;
f[26][41]=6745;
f[26][42]=13603;
f[26][43]=25607;
f[26][44]=47526;
f[26][45]=83655;
f[26][46]=143658;
f[26][47]=237470;
f[26][48]=385455;
f[26][49]=605735;
f[26][50]=931007;
f[26][51]=1398231;
f[26][52]=2056961;
f[26][53]=2962056;
f[26][54]=4192033;
f[26][55]=5824555;
f[26][56]=7963132;
f[26][57]=10710235;
f[26][58]=14199444;
f[26][59]=18555590;
f[26][60]=19609442;
f[27][34]=1;
f[27][35]=4;
f[27][36]=32;
f[27][37]=90;
f[27][38]=251;
f[27][39]=632;
f[27][40]=1488;
f[27][41]=3410;
f[27][42]=7264;
f[27][43]=14784;
f[27][44]=28944;
f[27][45]=54131;
f[27][46]=98241;
f[27][47]=170994;
f[27][48]=290326;
f[27][49]=478339;
f[27][50]=767779;
f[27][51]=1202059;
f[27][52]=1839030;
f[27][53]=2757412;
f[27][54]=4043343;
f[27][55]=5827628;
f[27][56]=8239749;
f[27][57]=11463004;
f[27][58]=15676328;
f[27][59]=21139108;
f[27][60]=22571394;
f[28][35]=1;
f[28][36]=5;
f[28][37]=28;
f[28][38]=62;
f[28][39]=257;
f[28][40]=594;
f[28][41]=1517;
f[28][42]=3365;
f[28][43]=7425;
f[28][44]=15733;
f[28][45]=31240;
f[28][46]=60485;
f[28][47]=110954;
f[28][48]=199209;
f[28][49]=345135;
f[28][50]=581912;
f[28][51]=953722;
f[28][52]=1525034;
f[28][53]=2377078;
f[28][54]=3631796;
f[28][55]=5423762;
f[28][56]=7955930;
f[28][57]=11444692;
f[28][58]=16197281;
f[28][59]=22523621;
f[28][60]=24339722;
f[29][36]=1;
f[29][37]=4;
f[29][38]=20;
f[29][39]=58;
f[29][40]=224;
f[29][41]=592;
f[29][42]=1494;
f[29][43]=3560;
f[29][44]=7839;
f[29][45]=16776;
f[29][46]=34252;
f[29][47]=67179;
f[29][48]=126702;
f[29][49]=231429;
f[29][50]=408295;
f[29][51]=701564;
f[29][52]=1171497;
f[29][53]=1907196;
f[29][54]=3032711;
f[29][55]=4713335;
f[29][56]=7171806;
f[29][57]=10701482;
f[29][58]=15668763;
f[29][59]=22542186;
f[29][60]=24587542;
f[30][37]=1;
f[30][38]=3;
f[30][39]=30;
f[30][40]=69;
f[30][41]=190;
f[30][42]=529;
f[30][43]=1456;
f[30][44]=3485;
f[30][45]=8051;
f[30][46]=17352;
f[30][47]=36631;
f[30][48]=72962;
f[30][49]=140886;
f[30][50]=262577;
f[30][51]=473028;
f[30][52]=829114;
f[30][53]=1411910;
f[30][54]=2345136;
f[30][55]=3798415;
f[30][56]=6016396;
f[30][57]=9320082;
f[30][58]=14155834;
f[30][59]=21078072;
f[30][60]=23250873;
f[31][38]=1;
f[31][39]=5;
f[31][40]=12;
f[31][41]=67;
f[31][42]=172;
f[31][43]=545;
f[31][44]=1386;
f[31][45]=3415;
f[31][46]=8094;
f[31][47]=18248;
f[31][48]=38716;
f[31][49]=79473;
f[31][50]=155650;
f[31][51]=296832;
f[31][52]=544029;
f[31][53]=974636;
f[31][54]=1687039;
f[31][55]=2857150;
f[31][56]=4705372;
f[31][57]=7588477;
f[31][58]=11956416;
f[31][59]=18475460;
f[31][60]=20552576;
f[32][40]=6;
f[32][41]=12;
f[32][42]=48;
f[32][43]=187;
f[32][44]=456;
f[32][45]=1323;
f[32][46]=3234;
f[32][47]=7817;
f[32][48]=18276;
f[32][49]=39529;
f[32][50]=84206;
f[32][51]=168322;
f[32][52]=328981;
f[32][53]=615058;
f[32][54]=1124953;
f[32][55]=1985213;
f[32][56]=3423563;
f[32][57]=5741359;
f[32][58]=9427267;
f[32][59]=15110300;
f[32][60]=16986772;
f[33][40]=1;
f[33][41]=6;
f[33][42]=13;
f[33][43]=41;
f[33][44]=138;
f[33][45]=467;
f[33][46]=1196;
f[33][47]=3378;
f[33][48]=7937;
f[33][49]=18732;
f[33][50]=41650;
f[33][51]=89584;
f[33][52]=182528;
f[33][53]=363002;
f[33][54]=691687;
f[33][55]=1286040;
f[33][56]=2312324;
f[33][57]=4058477;
f[33][58]=6930291;
f[33][59]=11568351;
f[33][60]=13099723;
f[34][40]=1;
f[34][42]=2;
f[34][43]=9;
f[34][44]=43;
f[34][45]=129;
f[34][46]=400;
f[34][47]=1152;
f[34][48]=3080;
f[34][49]=7899;
f[34][50]=18802;
f[34][51]=42688;
f[34][52]=93480;
f[34][53]=195094;
f[34][54]=394184;
f[34][55]=766167;
f[34][56]=1451445;
f[34][57]=2660101;
f[34][58]=4750206;
f[34][59]=8255368;
f[34][60]=9429440;
f[35][43]=1;
f[35][44]=11;
f[35][45]=34;
f[35][46]=122;
f[35][47]=390;
f[35][48]=1122;
f[35][49]=3053;
f[35][50]=7608;
f[35][51]=18904;
f[35][52]=43488;
f[35][53]=96707;
f[35][54]=206953;
f[35][55]=424901;
f[35][56]=844812;
f[35][57]=1624428;
f[35][58]=3029613;
f[35][59]=5501887;
f[35][60]=6329481;
f[36][45]=9;
f[36][46]=30;
f[36][47]=102;
f[36][48]=369;
f[36][49]=1004;
f[36][50]=2802;
f[36][51]=7428;
f[36][52]=18542;
f[36][53]=43870;
f[36][54]=99468;
f[36][55]=215849;
f[36][56]=453081;
f[36][57]=916027;
f[36][58]=1795035;
f[36][59]=3409347;
f[36][60]=3948081;
f[37][43]=1;
f[37][44]=1;
f[37][45]=3;
f[37][46]=9;
f[37][47]=37;
f[37][48]=88;
f[37][49]=347;
f[37][50]=915;
f[37][51]=2637;
f[37][52]=7216;
f[37][53]=18388;
f[37][54]=43716;
f[37][55]=102008;
f[37][56]=224137;
f[37][57]=479674;
f[37][58]=986412;
f[37][59]=1969264;
f[37][60]=2289058;
f[38][45]=1;
f[38][46]=2;
f[38][47]=5;
f[38][48]=25;
f[38][49]=79;
f[38][50]=302;
f[38][51]=860;
f[38][52]=2523;
f[38][53]=6764;
f[38][54]=17534;
f[38][55]=43377;
f[38][56]=102600;
f[38][57]=230988;
f[38][58]=502376;
f[38][59]=1052508;
f[38][60]=1230258;
f[39][47]=2;
f[39][48]=1;
f[39][49]=28;
f[39][50]=72;
f[39][51]=272;
f[39][52]=801;
f[39][53]=2402;
f[39][54]=6469;
f[39][55]=17436;
f[39][56]=42878;
f[39][57]=103408;
f[39][58]=236069;
f[39][59]=523725;
f[39][60]=613548;
f[40][49]=5;
f[40][50]=16;
f[40][51]=66;
f[40][52]=207;
f[40][53]=717;
f[40][54]=2139;
f[40][55]=6095;
f[40][56]=16522;
f[40][57]=41827;
f[40][58]=102731;
f[40][59]=239754;
f[40][60]=282015;
f[41][49]=1;
f[41][50]=1;
f[41][51]=18;
f[41][52]=63;
f[41][53]=191;
f[41][54]=681;
f[41][55]=2020;
f[41][56]=5662;
f[41][57]=15958;
f[41][58]=40778;
f[41][59]=101947;
f[41][60]=119237;
f[42][51]=4;
f[42][52]=10;
f[42][53]=51;
f[42][54]=164;
f[42][55]=569;
f[42][56]=1781;
f[42][57]=5257;
f[42][58]=14784;
f[42][59]=39537;
f[42][60]=46135;
f[43][52]=1;
f[43][53]=9;
f[43][54]=27;
f[43][55]=157;
f[43][56]=482;
f[43][57]=1627;
f[43][58]=4861;
f[43][59]=14177;
f[43][60]=16552;
f[44][52]=1;
f[44][53]=1;
f[44][54]=11;
f[44][55]=34;
f[44][56]=123;
f[44][57]=471;
f[44][58]=1474;
f[44][59]=4542;
f[44][60]=5394;
f[45][55]=5;
f[45][56]=26;
f[45][57]=111;
f[45][58]=403;
f[45][59]=1353;
f[45][60]=1629;
f[46][55]=2;
f[46][56]=6;
f[46][57]=36;
f[46][58]=82;
f[46][59]=353;
f[46][60]=435;
f[47][56]=1;
f[47][57]=4;
f[47][58]=23;
f[47][59]=89;
f[47][60]=106;
f[48][58]=2;
f[48][59]=16;
f[48][60]=24;
f[49][58]=1;
f[49][59]=5;
f[50][59]=1;
f[50][60]=1;
f[51][60]=1;
  scanf("%lld",&n);
  int len=0;
  int num=0;
  while (n){
    len++;
    num+=n%2;
    n/=2;
  }
  /*int ans=0;
  //printf("%d %d\n",len,num);
  down=(1ll<<(len-1))+(1ll<<(num-1))-1;
  up=(1ll<<(len))-(1ll<<(len-num));
  //printf("%lld %lld\n",down,up);
  int d=sqrt(down),u=sqrt(up);
  //printf("%d %d\n",d,u);
  if ((long long)d*d!=down) d++;
  long long dirta=2*d+1;
  for (long long val=d*d;val<=up;){
    if (popcount(val)==num)ans++;
    val+=dirta;
    dirta++;
    dirta++;
  }*/
  printf("%d\n",f[num][len]);
}