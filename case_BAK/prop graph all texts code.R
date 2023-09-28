library(ggplot2)
library(tidyverse)
library(dplyr)

#tibbles for adpositional realisation proportion
props_new <- alltexts_grouped %>% group_by(textname, func) %>% summarise(prop = mean(nominal_phrase_adpo_marked == "y", na.rm=TRUE))

theme_set(
  theme_classic() 
)

p <- ggplot(props_of_main_functions_grouped, aes(x=date, y=prop, group= func)) +
  geom_line(size=1, aes(linetype=func))+
  geom_point(size=2, aes(linetype= func)) +labs(y= "Proportion of adpositional realisation", x = "Time") + theme_gray()

print(p)



## change order of func in the legend
props_of_main_functions_grouped$func <- factor(props_of_main_functions_grouped$func, levels = c("com", "ass", "ins", "abl", "agent", "ben", "loc", "temp", "goal", "recip", "poss", "dobj", "subj"))
#changing title and labels
f <- p + ggtitle("Diachronic adpositional proportions")
print(f)

#colours: #F8766D #DB8E00 #AEA200 #64B200 #00BD5C #00C1A7 #00BADE #00A6FF #B385FF #EF67EB #FF63B&

write_excel_csv(props, file = "props of main functions_grouped.csv")

