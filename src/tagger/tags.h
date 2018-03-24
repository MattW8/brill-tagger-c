//
//  tags.h
//  
//
//  Created by Nicholas Weiland
//
#ifndef tags_h
#define tags_h
/* comparing hash values allows us 
to avoid expensive strcmp operations */
typedef enum{
    APPGE=404153362,
    AT=22741146,
    AT1=1478174539,
    BCL=1478177718,
    CC=22741259,
    CCB=1478181933,
    CS=22741275,
    CSA=1478182972,
    CSN=1478182985,
    CST=1478182991,
    CSW=1478182994,
    DA=22741322,
    DA1=1478185979,
    DA2=1478185980,
    DAR=1478186044,
    DAT=1478186046,
    DB=22741323,
    DB2=1478186045,
    DD=22741325,
    DD1=1478186174,
    DD2=1478186175,
    DDQ=1478186238,
    DDQGE=454413962,
    DDQV=1592825076,
    EX=22741410,
    FO=22741466,
    FU=22741472,
    FW=22741474,
    GE=22741521,
    IF=22741652,
    II=22741655,
    IO=22741661,
    IW=22741669,
    JJ=22741721,
    JJR=1478211979,
    JJT=1478211981,
    JK=22741722,
    MC=22741909,
    MC1=1478224134,
    MC2=1478224135,
    MCGE=1595291809,
    MCMC=1595292197,
    MD=22741910,
    MF=22741912,
    ND1=1478228424,
    NN=22741985,
    NN1=1478229074,
    NN2=1478229075,
    NNA=1478229122,
    NNB=1478229123,
    NNL1=1595613182,
    NNL2=1595613183,
    NNO=1478229136,
    NNO2=1595613378,
    NNT1=1595613702,
    NNT2=1595613703,
    NNU=1478229142,
    NNU1=1595613767,
    NNU2=1595613768,
    NP=22741987,
    NP1=1478229204,
    NP2=1478229205,
    NPD1=1595621112,
    NPD2=1595621113,
    NPM1=1595621697,
    NPM2=1595621698,
    PN=22742115,
    PN1=1478237524,
    PNQO=1596162819,
    PNQS=1596162823,
    PNQV=1596162826,
    PNX1=1596163212,
    PPGE=1596170609,
    PPH1=1596170622,
    PPHO1=671879405,
    PPHO2=671879406,
    PPHS1=671879665,
    PPHS2=671879666,
    PPIO1=671883630,
    PPIO2=671883631,
    PPIS1=671883890,
    PPIS2=671883891,
    PPX1=1596171662,
    PPX2=1596171663,
    PPY=1478237726,
    RA=22742232,
    REX=1478245460,
    RG=22742238,
    RGQ=1478245583,
    RGQV=1596682501,
    RGR=1478245584,
    RGT=1478245586,
    RL=22742243,
    RP=22742247,
    RPK=1478246162,
    RR=22742249,
    RRQ=1478246298,
    RRQV=1596728976,
    RRR=1478246299,
    RRT=1478246301,
    RT=22742251,
    TO=22742376,
    UH=22742434,
    VB0=1478262093,
    VBDR=1597759027,
    VBDZ=1597759035,
    VBG=1478262148,
    VBI=1478262150,
    VBM=1478262154,
    VBN=1478262155,
    VBR=1478262159,
    VBZ=1478262167,
    VD0=1478262223,
    VDD=1478262275,
    VDG=1478262278,
    VDI=1478262280,
    VDN=1478262285,
    VDZ=1478262297,
    VH0=1478262483,
    VHD=1478262535,
    VHG=1478262538,
    VHI=1478262540,
    VHN=1478262545,
    VHZ=1478262557,
    VM=22742504,
    VMK=1478262867,
    VV0=1478263393,
    VVD=1478263445,
    VVG=1478263448,
    VVGK=1597843715,
    VVI=1478263450,
    VVN=1478263455,
    VVNK=1597844170,
    VVZ=1478263467,
    XX=22742645,
    ZZ1=1478280554,
    ZZ2=1478280555,
    COL=349823,
    DQ=349799,
    SCOL=349824,
    LPAR=349805,
    RPAR=349806,
    PER=349811,
    COM=349809,
    QUE=349828,
    ZZ=22742777
}tag_hash_t;

/* converts hashed tag to string for printed output */
void hash_to_tag(int, char *);

/* hash function for matching tag with tag_hash_t */
int tag_to_hash(char *);

#endif /* tags_h */