Intro

The repository for the third case study of the paper, case, contains 6
files: the two plots included in the paper, the two corresponding
dataframes (adpo_props_facet.csv and adpo_props.csv), the corresponding
R ggplot code file (adpositional_realization_proportion_graph_code.R)
and all the annotated texts (annotated_texts.csv).

This readme details the corpus data used and how it has been manipulated
by the authors. The code file further contains #comments clarifying how
ggplot was used to create the two plots.

Corpus data

The corpus data is from Annotated Corpus of Pre-Standardized Balkan
Slavic Literature, which is available for download from
https://gitlab.uzh.ch/uzh-slavic-corpora/pre-standardized-balkan-slavic-literature).
Many of the corpus texts can be further explored through the online
interface at https://www.punco.uzh.ch/. 19 texts from this corpus are
included in the data in this paper, dated from c. 1340 to 1860. These
are listed below with the authors' numbering, text title/detail and
date:

24\. Manasses Chronicle- Legend of Troy, Pověsti o izvěstovannyix veštei
eže o kralexъ pričę. c.1340

31\. Zograph Miscellany, žitïe î+ žíznь+ prpdbnyǫ+ matere+ nášę+
para_skevî. 1380s

32\. Slovo Paraskevi, st҃yʺjeî prpdbniî paraskéviì. 1500s

29\. Šimon Kožičić, Šimona Kožičića Zadranina biskupa Modruškoga: od
žitiě rimskig\' arxierěov\' i cesarov\'. 1531

20\. Tixon.d. Žitie prěpodobnye matere našee Petky Trьnovskye.
1650-1670s

26\. Tixon.d.damian, Pametь styx bezsrebrьnikь Kozma i Damianь. 1660s

35\. NBKM 709, žítïe prpo_dobnïe mátere náši pétky trьnov\'sky. 1690s

8\. NBKM 328, Radi blaženoju Taïsïju. 1749-50

19\. Temski r. Slovo o nakazanii dětei. 1764

9\. NBKM 370, Istoria Slavěnobolgarskaa - Predislovie. 1784

16\. PPS, Pop Punčov Sbornik. 1796

1\. Berl.d., Slóvo styę prpdbnïę mtre nášīę Pét\'kĭ. 1791-1803

15\. Nedelnik1806, Skazanie o žitie prepodobnyę matere našeę Paraskevi
Ternovskię. 1806

5\. Krčovski 1814, Slovo vtoroe svętago proroka Daniila. 1814

11\. NBMK 1064, Živeenitu i na sfetae prepodobnae maika našja Petka
Tarnovskaja. 1820s

13\. NBKM 1081, Homily of St. Prophet Daniel, Homily of a certain
hermit. 1821

10\. NBKM 728, Žitie prepodobnaę Paraskeva. 1820s-30s

23\. Nedělnik 1856, Oktomvrię 14. za svętaę Paraskeva. 1856

17\. Rai.d., Slovo ftoroe zaradi Gospodovata sadovie sfetago proroka
Daniila. 1860

Data manipulation

The authors have made the following changes to the texts in the corpus
as follows. Most importantly for the paper, each adpositional and
nominal phrase was tagged with one of a number of function tags
reflecting their grammatical role in the bigger phrase/clause (as
opposed to morphological case marking). These are found in the func
column of the annotated_texts file. Each function tag is briefly
described below:

Subj- subject. Tags what is often considered the syntactic or
grammatical subject of a sentence. These can be intransitive or
transitive subjects and are mostly agentive.

Dobj- direct object. Tags what is often considered the syntactic or
grammatical direct object of a sentence. Less transitive 'objects' are
marked with the goal tag.

Poss- possessive. Tags the possessor, whether this is a genitively
marked noun or a possessive adjective, and includes partitive relations.

Recip- recipient. Tags the indirect object of the verb 'to give'.

Goal- goal. Tags less transitive 'objects' of less transitive verbs e.g.
'pray to', 'worship', 'follow', 'command'. Instances concerning physical
movement or certain abstract movements to a location are tagged with the
loc tag.

Loc- locative. Tags spatial relations and movements to and from
locations e.g. 'in the world', 'into the desert' as well as
locative-temporal relations such as 'on Tuesday'.

Abl- ablative. Tags instances of abstract movement away from a point in
time or space as well as causative relations. Movement away from
locations, especially involving physical movement, is tagged with the
loc tag.

Ins- instrumental. Tags the stereotypical use of the instrumental
morphological case i.e. that of an instrument or method by which an
action is completed, such as 'they paganized their baptism with accursed
divination and magic'. These instances are mostly inanimate, with
animate instances tagged by an agentive tag (not included in the plots
or analysis of this paper).

Ass- associative. Tags phrases of accompaniment or co-presence e.g. 'And
he sent St. Cosmas and Damian to their home with great honors.'

Com- comitative. Tags the stereotypical use of the comitative case but
is restricted to agentive instances- in other words, instances where
both parties are active in the action e.g. 'I do not dare to do so, to
go with you'. Inanimate or non-agentive instances are tagged with the
ass tag.

In addition to the function tags, each nominal phrase was tagged with
respect to whether it is marked with an adposition or not (y or n) in
the nominal_phrase_adpo_marked column. Further annotation additions made
by the authors are the func_detail, further_func, case_of_nom,
further_case and prep_marked columns, none of which are used in the
plots of this paper. Finally, the text names were added according to the
authors' numbering and the text date (given in the corpus metadata). The
annotated_texts file therefore includes all the changes made to the
corpus by the authors. Several columns from the original corpus texts
are not included in this file as they are not used by the authors.

The proportion of adpositional realization of each function listed above
was then calculated using the nominal_phrase_adpo_marked and func
columns to give the proportion (prop) in the adpo_prop and
adpo_prop_facet dataframes. A number of other functions are not included
in these dataframes for reasons of data size. The agentive tag mentioned
above is not often used, for instance. Instances where the function is
unclear (unk) are also disregarded. The dates of the texts in these two
dataframes are given as single years; in the case of time periods, a
midpoint is used.

The adpo_props_facet file and corresponding plot includes the
proportions for all the functions listed above whilst the adpo_props and
corresponding plot includes only com, ins, goal, recip and poss.
