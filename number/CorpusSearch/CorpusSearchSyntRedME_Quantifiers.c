nodes_only: t
node: NP*
define: ME1.def
ignore_nodes: CODE|'|"|,|E_S|/|RMV*


coding_query:

//  finds NPs with a plural noun and a quantifier:
1: {

  quant: (NP* iDoms Q*|Q)
        AND (NP* iDoms NS)

  z: ELSE

}
// agreement between quantifier and noun: this layer has to be manually corrected but provides a first approximation

2: {
  agreement: (NP* iDoms Q*) AND (Q* iDoms +alle|ale|alla|alle|Alle|$alle|ALLE|alre|ealla|ealle|Ealle|ane|anie|anye|ba|bo+t=e=|bo+te|Bo+te|bothe|eche|eueriche|fewe|fiewe|feawe|veawe|ueawe|halfe|halle|ilke|lute|manie|Manie|manye|Manye|MANYE|menye|monie|Monie|monye|Monye|mani+ge|Mani+ge|meche|moche|muche|myche|micele|michele|muchele|nane|Nane|none|oghte|some|somme|Somme|sume|Sume|summe|Summe|ulche|yche)
  no-agreement: (NP* doms Q*) AND (Q* iDoms +anigen|al|Al|all|All|eall|ani|any|eny|ony|both|ech|ei|ei+der|Ei+der|euery|every|few|f+au|fa|faa|half|lit|lut|litil|lutel|lytel|mani|Mani|many|Many|meny|Meny|moni|monny|mony|Mony|manig|mech|mekill|michel|michell|muchel|nan|non|noon|som|Som|ssum|sum|$Sum|Sum|zome|Zome|+alces|alles|ealles|mani+ges|nanes|summes)
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

// number of syllables: first approximation. Needs to be manually corrected.

6: {
  monosyllabic: (NP* iDoms Q*) AND (Q* iDoms ulche|yche|som|Som|ssum|sum|$Sum|Sum|zome|Zome|some|somme|Somme|sume|Sume|summe|Summe|summes|nane|oghte|Nane|nanes|none|nan|non|noon|meche|moche|muche|myche|lit|lut|lute|ilke|halfe|half|halle|few|fewe|fiewe|feawe|veawe|ueawe|eche|ech|ei|both|ba|bo+t=e=|bo+te|Bo+te|bothe|al|Al|all|All|eall|+alces|+alle|ale|alla|alle|Alle|$alle|ALLE|alles|alre|ealla|ealle|Ealle|ealles)
  pollisyllabic: (NP* iDoms Q*) AND (Q* iDoms mekill|michel|michell|muchel|micele|michele|muchele|manig|mani+ge|Mani+ge|mani+ges|manig|mani|Mani|many|Many|meny|Meny|moni|monny|mony|Mony|manie|Manie|manye|Manye|MANYE|menye|monie|Monie|monye|Monye|ani|any|eny|ony|ane|anie|anye|+anigen|ei+der|Ei+der|euery|every|eueriche)
}
