library(ggplot2)
library(tidyverse)
library(dplyr)

theme_set(
  theme_classic() 
)

# adpositional proportions facet plot (all functions)
df <- adpo_props_facet
d <- ggplot(df, aes(x=date, y=prop)) + geom_point(color="#3d62a6") + geom_smooth(se=FALSE, span=1.5, color="black") + facet_wrap(.~func) + theme_bw() +
  labs(y= "Proportion of adpositional realization", x = "Time") +
  geom_point(aes(size=no_of_NPs))

# adpositional proportions second plot (com, ins, goal, recip and poss)
p <- ggplot(adpo_props, aes(x=date, y=prop, group= func)) + geom_smooth(se=FALSE, span=1.5, color="black") +
  (aes(linetype=func))+
   labs(y= "Proportion of adpositional realization", x = "Time") + theme_gray() +ylim(0,1) + labs(linetype= 'Function')
print(p)  
d

## change order of funcs
adpo_props_facet$func <- factor(adpo_props_facet$func, levels = c("comitative", "associative", "instrumental", "ablative", "locative", "goal", "recipient", "possessive", "direct object", "subject")) 

