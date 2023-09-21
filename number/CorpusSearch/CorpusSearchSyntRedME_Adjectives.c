nodes_only: t
node: NP*
define: ME1.def
ignore_nodes: CODE|'|"|,|E_S|/|RMV*


coding_query:

//  position of the strong adjective in nominative NPs with a plural noun. Prenominal contexts with no determiner, and posnominal adjectives in general
1: {

  multiple:(NP* iDoms [1]ADJP|ADJ)
        AND (NP* iDoms [2]ADJP|ADJ)
        AND (NP* iDoms NS)

  Conjoined: (NP* iDoms ADJP|ADJ)
          AND (ADJP|ADJ iDoms CONJ*)

  prenominal: (NP* iDoms ADJP|ADJ) // this eliminates superlatives and comparative adjectives
          AND (NP* iDoms NS) //only finds plural nouns
          AND (NS iDoms !a*|A*|e*|E*|i*|I*|o*|O*|u*|U*) // eliminates nouns starting with a vowel which can an effect on agreement of the preceding adjective
          AND (NP* iDoms !D*|Q*) // eliminates determiners and quantifiers
          AND (NP* iDoms !PRO*|NP-POS|NPR*) // eliminates possessive pronouns and noun phrases
          AND (NP* iDoms !NEG)
          AND (ADJP|ADJ precedes NS)

  postnominal: (NP* iDoms ADJ|ADJP)
          AND (NP* iDoms NS)
          AND (NS precedes ADJ|ADJP)

  z: ELSE

}

//this codes whether there is agreement or not between the noun and the adjective. This layer needs to be manually corrected, but provides a first approximation.

2: {
  french-agree: (NP* doms ADJ) AND (ADJ iDoms duches|germayns|likerouses|meridionales|pardurables|perdurables|priuees|reguleres|uenimouses|temporels|vileyns|principals|arabiens|cardinals|dis-confortables|equales|EQUALES|fixes|diuerses|yndyenes|Reguleres|cardynalles|adventures|alienes|capitals|cardinals|equals|espirituels|mervayles|inequales|INEQUALES|vilens|preciouses|principales|priue`|sarizyneis|sotyls|temporeles|wyldes)
  adverbial-ly: (NP* doms ADJ) AND (ADJ iDoms *ly|*li)
  e-ending: (NP* doms ADJ) AND (ADJ iDoms domkete|doutable|drie|dru+ge|drye|f+agere|fa+ge|actyue|fensabylle|feole|ferme|eche|abhominable|actyfe|aloone|amyable|bale|blasfeme|charitable|contrarie|contrarye|defensabylle|delauey|delectabil|delectable|deorewur+de|deorrewur+de|dere|derfre|deue|nyce|Straunge|swete|dearne|swet|large|voide|unclene|+ticke|grene|rude|solempne|huge|Inre|resonable|semblable|fol|fole|foule|rice|riche|ryche|treowe|trewe|Treowe|simple|feble|litle|lutle|noble|symple|SYMPLE|vnable|poore|pore|poure|vnnumberable|hare|hende|knowable|lene|little|lyttill|luitel|meritorie|mis-bilieuede|murie|narewe|pale|pryuate|raye|scherne|sobre|square|sy+gke|+tynne|tu+de|unclene|unwreaste|vnsowe|weddynge|clene|cleane|straunge|strange|wicke|sweete|swete|ffre|fiewe|fre|freel|horribull|horryble|horrybyl|isene|kene|kinewur+de|kuade|kueade|lach+ge|lege|li+de|li+dere|like|lyke|mene|$mery|moevable|myddyll|necessarie|nedy|notabel|notabill|notabyl|odde|orrible|paynyme|peesible|por|pouere|prevy|priue|privee|profitabel|propre|queade|ripe|ruyde|same|sanquine|sencible|sengyl|sensible|simpil|sober|stille|strawnge|sympylle|trew|unable|undigne|unorne|uttere|vif|vile|vn-clene|vnclene|vnresonable|vnresynabull|vnspekable|wanspedie|wedde|wikke|wrecce|Wrecce|wrecche|Wrecche|wreche|zuete)
  agreement: (NP* doms ADJ) AND (ADJ iDoms *e|*um)
  no-agreement: (NP* doms ADJ) AND (ADJ iDoms !*e)
  z: ELSE
}

// Texts names:
3: {

    Chronicles: (CMPETERB-M1* inID)
    Vices: (CMVICES1* inID)
    Trinity: (CMTRINIT* inID)
    Kentish-homilies: (CMKENTHO-M1* inID)
    Katherine-group: (CMSAWLES*|CMHALI*|CMKATHE*|CMJULIA*|CMMARGA* inID)
    Ancrene: (CMANCRIW* inID)
    Lambeth: (CMLAMB* inID)

    Ayenbyte: (CMAYENBI-M2* inID)
    Kentish-sermons: (CMKENTSE-M2* inID)
    Aelred: (CMAELR3-M23* inID)
    Psalter: (CMEARLPS* inID)
    Richard-rolle: (CMROLLEP-M24*|CMROLLTR-M24* inID)

    Polychronicon: (CMPOLYCH-M3* inID)
    New-testament: (CMNTEST-M3* inID)
    Purvey: (CMPURVEY-M3* inID)
    Horses: (CMHORSES-M3* inID)
    Royal: (CMROYAL-M34* inID)
    Parson: (CMCTPARS-M3* inID)
    Melibee: (CMCTMELI-M3* inID)
    Equatorie: (CMEQUATO-M3* inID)
    Boethious: (CMBOETH-M3* inID)
    wycliffite: (CMWYCSER-M3* inID)
    Old-testament: (CMOTEST-M3* inID)
    Cloud: (CMCLOUD-M3* inID)
    Mandeville: (CMMANDEV-M3* inID)
    Astrolabe: (CMASTRO-M3* inID)
    Hilton: (CMHILTON-M34* inID)
    Book-vices: (CMVICES4-M34* inID)
    Norwich: (CMJULNOR-M34* inID)
    Edmund: (CMEDVERN-M3* inID)
    Brut: (CMBRUT3-M3* inID)
    Mirk: (CMMIRK-M34* inID)
    Benrul: (CMBENRUL-M3* inID)
    Edthor: (CMEDTHOR-M34* inID)
    Gaytry: (CMGAYTRY-M34* inID)

    Gregory: (CMGREGOR-M4* inID)
    Innocencium: (CMINNOCE-M4* inID)
    Aelred-m4: (CMAELR4-M4* inID)
    Edmund-m4: (CMEDMUND-M4* inID)
    Kempe: (CMKEMPE-M4* inID)
    Capgrave-sermon: (CMCAPSER-M4* inID)
    Capgrave-chrnicle: (CMCAPCHR-M4* inID)
    Reynes: (CMREYNES-M4* inID)
    Reynard: (CMREYNAR-M4* inID)
    Morte-a:(CMMALORY-M4* inID)
    Siege-j: (CMSIEGE-M4* inID)
    medicinis: (CMTHORN-MX4* inID)

    z: ELSE
}


//Year:
4: {
    \1150: (CMKENTHO-M1*|CMPETERB-M1* inID)
    \1225: (CMVICES1*|CMSAWLES*|CMHALI*|CMKATHE*|CMJULIA*|CMMARGA*|CMLAMB*|CMTRINIT* inID)
    \1230: (CMANCRIW* inID)
    \1275: (CMKENTSE-M2* inID)
    \1325: (CMAELR3-M23* inID)
    \1340: (CMAYENBI-M2* inID)
    \1350: (CMEARLPS*|CMROLLEP-M24*|CMROLLTR-M24*|CMEDTHOR-M34* inID)
    \1380: (CMPOLYCH-M3*|CMNTEST-M3*|CMPURVEY-M3*|CMBOETH-M3*|CMOTEST-M3* inID)
    \1390: (CMEDVERN-M3*|CMCTPARS-M3*|CMCTMELI-M3*|CMEQUATO-M3*|CMASTRO-M3*|CMHILTON-M34* inID)
    \1400: (CMBRUT3-M3*|CMWYCSER-M3*|CMCLOUD-M3*|CMMANDEV-M3*|CMVICES4-M34*|CMJULNOR-M34* inID)
    \1415: (CMMIRK-M34* inID)
    \1425: (CMBENRUL-M3*|CMROYAL-M34* inID)
    \1440: (CMGAYTRY-M34*|CMTHORN-MX4* inID)
    \1450: (CMHORSES-M3*|CMAELR4-M4*|CMKEMPE-M4*|CMEDMUND-M4*|CMCAPSER-M4* inID)
    \1460: (CMCAPCHR-M4* inID)
    \1470: (CMMALORY-M4* inID)
    \1475: (CMGREGOR-M4* inID)
    \1480: (CMREYNES-M4*|CMREYNAR-M4* inID)
    \1490: (CMINNOCE-M4*|CMSIEGE-M4* inID)

    z: ELSE
}

//Region:
5: {
    Southern: (CMAYENBI-M2*|CMKENTHO-M1*|CMKENTSE-M2*|CMPOLYCH-M3*|CMPURVEY-M3*|CMHORSES-M3*|CMROYAL-M34*|CMGREGOR-M4*|CMINNOCE-M4* inID)
    EM: (CMVICES1*|CMEARLPS*|CMTRINIT*|CMCTPARS*|CMOTEST*|CMPETERB-M1*|CMNTEST-M3*|CMAELR3-M23*|CMCTMELI-M3*|CMEQUATO-M3*|CMBOETH-M3*|CMWYCSER-M3*|CMOTEST-M3*|CMCLOUD-M3*|CMMANDEV-M3*|CMASTRO-M3*|CMHILTON-M34*|CMVICES4-M34*|CMAELR4-M4*|CMEDMUND-M4*|CMKEMPE-M4*|CMCAPSER-M4*|CMCAPCHR-M4*|CMREYNES-M4*|CMREYNAR-M4*  inID)
    WM: (CMLAMB*|CMSAWLES*|CMHALI*|CMKATHE*|CMJULIA*|CMMARGA*|CMANCRIW*|CMAELR3-M23*|CMEDVERN-M3*|CMBRUT3-M3*|CMMIRK-M34*|CMMALORY-M4*|CMSIEGE-M4* inID)
    Northern: (CMROLLEP-M24*|CMROLLTR-M24*|CMBENRUL-M3*|CMEDTHOR-M34*|CMGAYTRY-M34*|CMTHORN-MX4* inID)
    z: ELSE
}

6: {

  monosyllabic: (NP* doms ADJ) AND (ADJ iDoms ylle|wylde|woode|wode|wlonke|wide|weete|$warme|walsche|vuel|voule|uolle|+tike|+tik|syke|syb|swote|swifte|strayte|stiue|ssorte|soo+t|softe|so+de|snaw|smerte|slou|sike|shorte|sherpe|seruyle|seer|schille|quykke|quyke|quikke|quike|oolde|ofte|ny|neowe|neih|moche|mild|milde|lyghte|lych|lite|lihte|light|lease|last|hyghe|hy|hwite|hote|hool|holde|heorte|heighe|hege|hech+ge|grimme|greene|gay|fyn|fowle|fowl|folde|fixe|feste|fele|fel|feire|fatte|falde|egall|eelde|dyepe|dyade|$dumbe|Dumbe|dumbe|dome|derue|derk|derke|cool|colde|calde|brymme|broode|beare|bare|alde|$strong|strong|stronge|ahne|blak|blake|blynde|bri+gte|brighte|chast|chef|cheef|cleane|clene|clere|deed|dede|ded|dedelich|dead|deade|deed|deede|deef|Deef|depe|derf|doumpe|Dumbe|dumbe|doumbe|fair|Fair|faire|fayre|Fayre|fayr|fals|false|faste|fell|fel|fer|feor|fers|ferse|fole|foly|foule|folte|freel|frensche|frenshe|frenshce|Frensche|Frenche|frenche|freysh|freysshe|fressche|fresch|fulle|fule|full|ful|glade|gleade|god|gode|Gode|$gode|godde|Good|GOOD|good|goode|Goode|gude|gud|gold|grette|grett|grete|Grete|gret|greete|greet|greate|grat|grete|+gunge|+Gunge|+gonge|+geunge|+geong|Gunge|yonge|+Gonge|+gong|gilt|guod|guode|gude|gud|Goode|goode|GOOD|good|Gode|gode|god|halde|eld|elde|old|olde|olde|elde|harde|hard|herde|hate|hi+ge|hye|hy+ge|hy+g|hy|hehe|heh|he+ge|hey|hool|hole|ille|ill|Ille|iust|iuste|kene|kueade|kuade|lawe|lerde|lewde|lowde|licht|Lichte|lichte|long|longe|lyke|like|madde|meke|new|newe|ny|owne|poure|pore|poore|prude|Prowde|prowde|proude|pure|qwike|cwike|real|red|rede|ri+gt|ryght|richte|right|riht|rihte|rite|rice|riche|ryche|rounde|sad|same|sc+arpe|scharp|scharpe|sharp|sharpe|sharppe|schort|schorte|seke|sere|Sere|smale|small|smalle|smele|smarte|sore|sounde|sterke|stille|stoute|straite|Straite|strange|streyte|stronge|swarte|trew|trewe|ualse|uals|uayre|uoule|uele|uolle|uuele|uppe|vayne|veyne|whit|white|whyt|whyghte|whygth|whyte|$whyte|white|wete|vj=te=|whyght|wild|wilde|wise|wyse|wijse|wra+de|Wrecce|wrecce|wreche|zo+te)

  pollysillabic: (NP* doms ADJ) AND (ADJ iDoms yemere|wytty|wyckede|wra+tful|worshippfull|worshipfful|worshepful|worschepful|wor+ti|wopi|wondyr|wittie|willeful|wikkede|wikked|weyward|wete|westi|wantowne|vyolet|vnwyse|vnwor+tie|vnwijse|vnskillwyse|vnlauful|vnkynd|vniuste|vniust|vnfeithful|vn-wyse|vileyne|viciouse|verrey|verrene|venimouse|venial|vemens|valyaunte|utterliche|utewi+d|unwvyse|unwreste|unwitelese|unto+gene|untidi|unsauure|unrihte|unnette|unluuede|unluued|unbicumeliche|unait|un-whis|ulessliche|ufele|uertuous|turoneys|turonens|trusty|trowfeste|temperall|temperal|talewise|+teufule|synguler|synewe|swikele|suspekt|suspecte|supersticious|sunnefule|sunfule|sunderliche|sumerlich|sulliche|sufficient|stonun|spytues|specyall|speciale|special|sovereyn|sory|sorchfule|sondry|sodeyn|sodein|sinful|silken|serteyn|septemtrioneles|seofanfald|senfulle|sedicious|scornful|schrewyd|schendfule|sacred|rytful|rightful|right-wys|ri+gtuolle|reowfule|reow+dfule|rekles|reguler|rebel|quotidyan|pytous|presyous|presious|present|powyr|plentyuows|plenty|plentevows|perpetuell|perlyows|patent|openliche|openheuedede|nyeduolle|northeryn|northen|neodful|nakyd|naked|myghty|myghtles|mortel|mortal|$monifalde|moderles|michel|mi+gtful|meruelyows|meruelous|meruailous|medlese|medful|manifolde|manifeld|manifealde|malyscyus|lytyll|luueliche|$lufsumes|lu+ter|lostuolle|lostfolle|long-taylet|litel|licomliche|lichamliche|lewid|leufsume|lleoue|Leoue|eofe|Leofe|lecherys|layery|lawful|latyn|Latyn|ladliche|la+delese|kentisshe|kentische|jentylle|jentyl|inwarde|inward|inparfit|in-wardliche|ilich|ileaffulle|ihal|iful+gede|ifele|iewes|houenliche|homeliche|holie|hindre|hinderfulle|heuenliche|herty|helplese|hedows|he+gliche|he+dene|hastif|hardy|hali+ge|grisliche|griselich|golliche|godlese|gled-reade|gentylle|gastliche|gastlich|gasteliche|+geoluwe|+geluwe|freynysche|fleumatyk|flesliche|fleshliche|$flescliche|fleschy|flehsliche|flecsliche|firi|figuratyf|figuratijf|figuratif|ffleschliche|festyfull|feruent|ferial|ferful|ferdful|felefolde|fele-felde|feithful|federlese|federlase|fadyrles|fadirles|expresse|experte|evene|euen|euele|esy|estliche|espiritueel|esi|er+tliche|eor+dlichf|envyus|endelese|empty|eisfule|e+dele|dyuerce|dreduolle|doucet|diametral|devyllisshe|devowt|dependaunt|deliciouse|delicat|+delliche|dea+dliche|curious|croked|crokede|coveytous|cotidian|comune|compassyf|commune|comen|civil|celestial|cathedral|capitale|boystows|boistows|bodylyche|bodiliche|blody|bisye|bisie|besy|beasteliche|bastard|atterne|arrianus|ateliche|arraunte|apert|almytty|admod|abundawnt|$dusie|$worldliche|wurdliche|worldliche|worldlich|actyfe|actyu|alien|alyen|aliene|aloone|anoyouse|arlease|attefulle|attri|bi-lefulle|bileffulle|bilefulle|bicumeliche|biter|bittere|bittre|bitere|bittyr|byttere|byttyr|blameful|blasfeme|blisfulle|cartayne|certayne|certein|certeyn|certen|certeyne|certeine|coleryk|comyn|comun|contemplatife|conterfete|contrarye|coueitouse|couetous|couetouse|covetous|cristen|Cristen|cristene|Cristene|crysten|crystyne|Crysten|crystene|crystyn|Crysten|Cristen|deadliche|deorewur+de|deuoute|discrete|diuers|diuerse|dyuers|dyuerse|dyvers|dyverse|dyvyrs|dyversse|diverse|diverse|divers|diuerse|diuers|dolefull|dredfule|dredeful|dylicious|edie|eadie|eadi|eifulle|Englisch|englisch|Englische|englische|English|english|englisse|englisshe|Englisshe|Englysche|englysche|eng-lisshe|Eng-lisshe|eor+dliche|eor+deliche|Eor+deliche|equiuok|esy|evil|evel|euel|euell|euyll|famouse|feorliche|figuratyf|flesliche|fleschliche|$fleschliche|Fraynysche|fraynysche|Furen|furen|furene|galiche|general|gloueris|gloryous|glorious|gloriouse|goldene|golden|gold|golde|gostlich|gostliche|gredie|greuus|grevouse|griselic|hauenlese|hauelese|heouenliche|ethen|hethene|hethen|hea+dene|he-+tene|he+tene|hethyn|he+tene|he+ten|he+tone|heuie|honest|horrybull|hungri|idele|idel|ileafulle|ilewede|lewede|lewed|illich|ilyke|irene|irenen|irnenne|irnene|irous|iuil|iuele|Iuele|iuel|kinewur+de|lecherous|leprows|leprowse|leveful|lewyde|li+gt|lu+dere|li+dere|lusty|luuefule|luuie|meedful|meruelous|malicious|merveillous|mervaylous|merveylous|mervayles|midday|mislich|Misliche|misliche|mistliche|Modi|Moral|morall|moral|moralle|muchele|myhty|my+gti|nakyde|necessarie|nedfull|nedful|nihtliche|notabel|opyn|opin|open|outward|outwarde|owtwarde|parfite|parfit|parfyte|perfite|perpetuall|plesante|precyous|precious|preciouse|precyos|prevy|princypall|principall|principal|principale|profitabel|religyows|religiows|religiouse|religious|relygyous|relygious|reuliche|ri+gtful|ryghtful|ry+gtful|rihtwise|$rihtwise|ryghtwys|ryghtwyse|rightwyse|ri+gtwyse|Rightwyse|ru+derihsse|schameful|schamefull|seculer|secler|seculere|sekyr|seli|shepisse|skillwyse|smellinde|so+dfeste|sorweful|sorouful|sorowfull|spiritual|spyrytuall|stal-wor+t|stalewur+de|Straite|strotige|subtile|subtyle`|subtyll|sundri|sunfulle|synful|synfull|synfulle|Synful|suspecyous|swinisse|sympylle|+telliche|+tulliche|+tullich|temporele|temporeel|temporal|temporalle|temperelle|timeliche|timelich|timliche|trecherous|trefolde|trenchant|un-trume|un+deaufulle|Unbileuede|uncu+de|unnut|unnute|unriht|unweschene|unwhaynt|unwor+ty|venemous|venymous|venenouse|verrey|verray|vertuous|vertuouse|vncu+de|vnlyfful|vnlifful|vnlauful|vnshamful|vnworthi|vnwur+dliche|wattery|wanspedie|werie|wickded|wicked|wickede|wikkide|wycked|wykkyd|wykked|wondirfull|woundirfull|wonderful|worchipful|wordliche|Wordles|worthy|worthi|wrongful|wykked|wickid|wicked|Wicked|ydele|ydill|ydull|ydell|ydel|yfele|yuel|yuele|iuele|Iuele|euyl|Yfele|yuele)

  z: ELSE
}

// This section was originally intented to code for whether the adjective was intersective or non-intersective:

7: {
  intersective: (NP* doms ADJ) AND (ADJ iDoms  yuele)
  non-intersective: (NP* doms ADJ) AND (ADJ iDoms zo+te)
  z: ELSE
}
