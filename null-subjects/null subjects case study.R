library(tidyverse)
library(lme4)
library(DHARMa)
library(car)
library(ggsci)
library(gridExtra)

mydata <- read.csv('cordeles_2023.csv', header = TRUE, encoding = "UTF-8")
orality <- read.csv('orality.csv', header = TRUE, encoding = "UTF-8")

#get rid of duplicate data (translation of another text)
orality <- subset(orality, docID != "CPMTpoSP") 

#ORALITY ####
#plot
orality$Country <- ifelse(orality$country == "DR", "Dominican Republic", orality$country)
orality$Country <- factor(orality$Country)
orality_plot_regression <- ggplot(data = orality, aes(x = ORSCORE, y = OVERT_RATE)) + 
  #ylim(0, .3) +
  #xlim(0, 2.5) +
  geom_smooth(method = "lm", se = FALSE, color = "black") +
  labs(x="ORSCORE", y="Proportion of overt pronouns") + 
  geom_point(size=3.0, aes(pch = Country, color = Country)) + 
  #ggtitle(paste0("Orality")) + 
  theme_minimal() + scale_color_npg()

# save to external file
ggsave("orality.pdf", plot=orality_plot_regression, height=4, width=6)


#model
xmdl <- lm(OVERT_RATE ~ ORSCORE, data = orality)
summary(xmdl)

#PRONOUN PLOTS ####
pronoun_plot <- function(mydata, country, panelID, type="regular") {
  #make country specific (country, re-leveling, and year labels):
  data <- filter(mydata, Country == country)
  
  if (country == "Colombia") {
    data$docID <- factor(data$docID,levels = c("co16oyc", "co16evii", "co17vdm", "co17gnrg", "co18gsfb", "co18ppym", "co19ihdc", "CPMTpr", "CPMTpoOG", "CPMTpoSP", "CPMTpl", "co19syl"))
    docs <- c("1563\nOYC", "1589\nEVII", "1614\nVDM", "1674\nGNRG", "1787\nGSFB", "1792\nPPYM", "1844\nIHDC", "1877\nPR", "1877\nPOog", "1877\nPOsp", "1880\nPL", "1882\nSYL")
  } else if (country == "Dominican Republic") {
    data$docID <- factor(data$docID,levels = c("dr16sdj", "dr16ent", "dr17dphj", "dr18asd", "dr18livie", "dr19ald", "dr19gal"))
    docs <- c("1500\nSDJ", "1588\nENT", "1658\nDPHJ", "1752\nASD", "1785\nLIVIE", "1857\nALD", "1886\nGAL")
  } else if (country == "Bolivia") {
    data$docID <- factor(data$docID,levels = c("bo16rvp", "bo18hvip", "bo19adla", "bo19jdlr", "bo21iia"))
    docs <- c("1550\nRVP", "1721\nHVIP", "1839\nADLA", "1885\nJDLR", "2010\nIIA")
  } else if (country == "Panamá") {
    data$docID <- factor(data$docID,levels = c("pa16hgni", "pa16car", "pa17lldp", "pa17dlyd", "pa19mpe", "pa19hs"))
    docs <- c("1535\nHGNI", "1546\nCAR", "1638\nLLDP", "1695\nDLYD", "1872\nMPE", "1875\nHS")
  } else if (country == "Spain") {
    data$docID <- factor(data$docID,levels = c("sp16can", "sp16lah", "sp17dq", "sp17acra", "sp18arjd", "sp18eau", "sp19qdev", "sp19cpc"))
    docs <- c("1525\nCAN", "1551\nLAH", "1605\nDQ", "1664\nACRA", "1756\nARJD", "1786\nEAU", "1836\nQDEV", "1885\nCPC")
  }
  
  #plot (repeat for each country)
  barchart <- data %>% 
    ggplot(aes(x = docID, fill = sub_POS)) +
    scale_x_discrete(labels=docs) +
    geom_bar(position = "fill", aes(color=Genre, lty=Genre), linewidth = .6) +
    ylab("Proportion") +
    xlab("Document ID") +
    guides(fill=guide_legend(title="Pronoun"), color=guide_legend(override.aes=list(fill=NA), title="Genre")) +
    theme_minimal() + theme(panel.grid.major=element_blank(), panel.grid.minor=element_blank())
  
  barchart <- barchart + ggtitle(paste0("(", panelID, ") ", country, " (n = ", nrow(data), ")"))
  
  if (type == "supp") {
    #barchart <- barchart + scale_fill_manual(values = c("NULL" = "#7294D4", "OVERT" = "#C6CDF7")) + scale_color_manual(values = c("DOC" = "black", "LIT" = "white", "SUPP" = "gold")) + theme(axis.text.x = element_text(size = 9, color = "black"))
    barchart <- barchart + scale_fill_manual(values = c("OVERT" = "#3d62a6", "NULL" = "#dfe2f7")) + scale_color_manual(values = c("DOC" = "black", "LIT" = "black", "SUPP" = "black")) + theme(axis.text.x = element_text(size = 10, color = "black"), axis.text.y=element_text(color="black"))
    #supp genre ^^^
  } else if (type == "regular") {
    barchart <- barchart + scale_fill_manual(values = c("NULL" = "#7294D4", "OVERT" = "#C6CDF7")) + scale_color_manual(values = c("DOC" = "black", "LIT" = "white")) + theme(axis.text.x = element_text(size = 10, color = "black"), axis.text.y=element_text(color="black"))
    #regular ^^^
  }
  
  barchart
}

mydata$Country <- ifelse(mydata$Country == "DR", "Dominican Republic", mydata$Country)
mydata$Country <- factor(mydata$Country)

pp1 <- pronoun_plot(mydata, country="Colombia", type="supp", panelID="a")
pp2 <- pronoun_plot(mydata, country="Bolivia", type="supp", panelID="b")
pp3 <- pronoun_plot(mydata, country="Dominican Republic", type="supp", panelID="c")
pp4 <- pronoun_plot(mydata, country="Panamá", type="supp", panelID="d")
pp5 <- pronoun_plot(mydata, country="Spain", type="supp", panelID="e")

# combined plot
combined_plot <- grid.arrange(pp2, pp3, pp4, pp5, nrow=2, ncol=2, widths=c(0.85, 1.0))
combined_plot <- grid.arrange(pp1, combined_plot, nrow=2, ncol=1, heights=c(1.1,2))

# save to external file
ggsave("pronoun-combined.pdf", plot=combined_plot, height=10, width=9)

#MAIN MODEL####
#Get data ready
binary_null <- within(mydata, Country <- relevel(factor(Country), ref = "Spain")) #make Spain the reference level for Country
binary_null <- within(binary_null, Macro_Region <- relevel(factor(Macro_Region), ref = "Spain")) #make Spain the reference level for Macro_Region

binary_null %>% select(Region, Genre, sub_POS, Country, Year, ORSCORE, docID, Century, Macro_Region) %>% 
  na.omit() %>% 
  mutate(Century = as.factor(Century)) -> binary_null

binary_null <- subset(binary_null, binary_null$docID != "CPMTpoSP") #get rid of duplicate data (translation of another text)

#Model
binary_null_mdl_int <- glmer(factor(sub_POS) ~ scale(Year) * scale(ORSCORE) + Macro_Region + (1|docID), 
                             data = binary_null, 
                             family = 'binomial')

#TESTS####
summary(binary_null_mdl_int)
drop1(binary_null_mdl_int, test = "Chisq")
Anova(binary_null_mdl_int, type = "III")
AIC(binary_null_mdl_int)

#checking residuals
res_orality <- simulateResiduals(xmdl, plot = T)
res <- simulateResiduals(binary_null_mdl_int, plot = T)