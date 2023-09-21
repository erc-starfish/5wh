library(tidyverse)
library(lme4)
library(DHARMa)
mydata <- read.csv('cordeles_2023.csv', header = TRUE, encoding = "UTF-8")
orality <- read.csv('orality.csv', header = TRUE, encoding = "UTF-8")

#Orality####
orality <- subset(orality, docID != "CPMTpoSP") #get rid of duplicate data (translation of another text)

#plot
orality_plot_regression <- ggplot(data = orality, aes(x = ORSCORE, y = OVERT_RATE)) + 
  ylim(0, .3) +
  xlim(0, 2.5) +
  geom_smooth(method = "lm", se = FALSE, color = "black") +
  labs(x="ORSCORE", y="Proportion of overt pronouns") +
  theme_minimal() 
orality_plot_regression + geom_point(aes(color = country)) + ggtitle(paste0("Orality")) + theme_minimal()

#model
xmdl <- lm(OVERT_RATE ~ ORSCORE, data = orality)
summary(xmdl)

#Pronoun Plots####
#make country specific (country, re-leveling, and year labels):
country <- "Colombia" #change for new country
data <- filter(mydata, Country == country) # change to "DR" for Dominican Republic

#un-comment the one you need below
data$docID <- factor(data$docID,levels = c("co16oyc", "co16evii", "co17vdm", "co17gnrg", "co18gsfb", "co18ppym", "co19ihdc", "co19syl", "CPMTpr", "CPMTpoOG", "CPMTpoSP", "CPMTpl"))
#data$docID <- factor(data$docID,levels = c("dr16sdj", "dr16ent", "dr17dphj", "dr18asd", "dr18livie", "dr19ald", "dr19gal"))
#data$docID <- factor(data$docID,levels = c("bo16rvp", "bo18hvip", "bo19adla", "bo19jdlr", "bo21iia"))
#data$docID <- factor(data$docID,levels = c("pa16hgni", "pa16car", "pa17lldp", "pa17dlyd", "pa19mpe", "pa19hs"))
#data$docID <- factor(data$docID,levels = c("sp16can", "sp16lah", "sp17dq", "sp17acra", "sp18arjd", "sp18eau", "sp19qdev", "sp19cpc"))

#un-comment the one you need below
docs <- c("1563\nOYC", "1589\nEVII", "1614\nVDM", "1674\nGNRG", "1787\nGSFB", "1792\nPPYM", "1844\nIHDC", "1882\nSYL", "1877\nPR", "1877\nPOog", "1877\nPOsp", "1880\nPL")
#docs <- c("1500\nSDJ", "1588\nENT", "1658\nDPHJ", "1752\nASD", "1785\nLIVIE", "1857\nALD", "1886\nGAL")
#docs <- c("1550\nRVP", "1721\nHVIP", "1839\nADLA", "1885\nJDLR", "2010\nIIA")
#docs <- c("1535\nHGNI", "1546\nCAR", "1638\nLLDP", "1695\nDLYD", "1872\nMPE", "1875\nHS")
#docs <- c("1525\nCAN", "1551\nLAH", "1605\nDQ", "1664\nACRA", "1756\nARJD", "1786\nEAU", "1836\nQDEV", "1885\nCPC")

#plot (repeat for each country)
barchart <- data %>% 
  ggplot(aes(x = docID, fill = sub_POS)) +
  scale_x_discrete(labels=docs) +
  geom_bar(position = "fill", aes(color=Genre), linewidth = .5) +
  ylab("percentage") +
  guides(fill=guide_legend(title="Pronoun"), color=guide_legend(title="Genre")) +
  ggtitle(paste0("Pronoun Realization: ", country))+
  theme_minimal()

barchart + scale_fill_manual(values = c("NULL" = "#7294D4", "OVERT" = "#C6CDF7")) + scale_color_manual(values = c("DOC" = "black", "LIT" = "white", "SUPP" = "gold")) + theme(axis.text.x = element_text(size = 5))
#supp genre ^^^

barchart + scale_fill_manual(values = c("NULL" = "#7294D4", "OVERT" = "#C6CDF7")) + scale_color_manual(values = c("DOC" = "black", "LIT" = "white")) + theme(axis.text.x = element_text(size = 5))
#regular ^^^

#Main Model####
#Get data ready
binary_null <- within(mydata, Country <- relevel(Country, ref = "Spain")) #make Spain the reference level for Country
binary_null <- within(binary_null, Macro_Region <- relevel(Macro_Region, ref = "Spain")) #make Spain the reference level for Macro_Region

binary_null %>% select(Region, Genre, sub_POS, Country, Year, ORSCORE, docID, Century, Macro_Region) %>% 
  na.omit() %>% 
  mutate(Century = as.factor(Century)) -> binary_null

binary_null <- subset(binary_null, binary_null$docID != "CPMTpoSP") #get rid of duplicate data (translation of another text)

#Model
binary_null_mdl_int <- glmer(sub_POS ~ scale(Year) * scale(ORSCORE) + Macro_Region + (1|docID), 
                             data = binary_null, 
                             family = 'binomial')
#tests
summary(binary_null_mdl_int)
drop1(binary_null_mdl_int, test = "Chisq")
Anova(binary_null_mdl_int, type = "III")
AIC(binary_null_mdl_int)

#checking residuals
res <- simulateResiduals(binary_null_mdl_int, plot = T)
