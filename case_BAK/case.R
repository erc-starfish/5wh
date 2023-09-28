library(ggplot2)
library(tidyverse)
library(dplyr)

#tibbles for adpositional realisation proportion
props_new <- alltexts_grouped %>% group_by(textname, func) %>% summarise(prop = mean(nominal_phrase_adpo_marked == "y", na.rm=TRUE))

theme_set(
  theme_classic() 
)

p <- ggplot(props_of_main_functions_grouped, aes(x=date, y=prop, group= func)) +
  #geom_line(size=1, aes(linetype=func))+
  #geom_point(size=2, aes(linetype= func))
	stat_summary(fun=mean)
#+labs(y= "Proportion of adpositional realisation", x = "Time") + theme_gray()

print(p)



## change order of func in the legend
props_of_main_functions_grouped$func <- factor(props_of_main_functions_grouped$func, levels = c("com", "ass", "ins", "abl", "agent", "ben", "loc", "temp", "goal", "recip", "poss", "dobj", "subj"))
#changing title and labels
f <- p + ggtitle("Diachronic adpositional proportions")
print(f)

#colours: #F8766D #DB8E00 #AEA200 #64B200 #00BD5C #00C1A7 #00BADE #00A6FF #B385FF #EF67EB #FF63B&

#write_excel_csv(props, file = "props of main functions_grouped.csv")


# proposed facet plot
df <- props_of_main_functions_grouped
p <- ggplot(df, aes(x=date, y=prop)) + geom_point(color="#3d62a6") + geom_smooth(se=FALSE, span=1.5, color="black") + facet_wrap(.~func) + theme_bw()
p <- ggplot(df[df$func %in% c("com", "ins", "goal", "recip", "poss"),] , aes(x=date, y=prop, group=func)) + geom_smooth(se=FALSE, span=1.5, color="black") + ylim(0,1) + theme_minimal()

require(ggrepel)
require(ggsci)
p <- ggplot(df[df$func %in% c("com", "ins", "goal", "recip", "poss"),] , aes(x=date, y=prop, group=func)) + geom_smooth(se=FALSE, span=1.5, aes(color=func)) + ylim(0,1) + theme_bw() + theme(legend.position="none") + scale_color_npg() + ylab("Proportion of adpositional realization") + xlab("Year")
labelsize <- 5.0
p <- p + geom_text_repel(data=data.frame(date=1600, prop=0.99, func="com"), nudge_x=-5, nudge_y=-0.07, size=labelsize, aes(label=func))
p <- p + geom_text_repel(data=data.frame(date=1680, prop=0.65, func="instrument"), nudge_x=-80, nudge_y=0.07, size=labelsize, aes(label=func))
p <- p + geom_text_repel(data=data.frame(date=1700, prop=0.59, func="goal"), nudge_x=50, nudge_y=-0.08, size=labelsize, aes(label=func))
p <- p + geom_text_repel(data=data.frame(date=1750, prop=0.31, func="recipient"), nudge_x=-50, nudge_y=0.05, size=labelsize, aes(label=func))
p <- p + geom_text_repel(data=data.frame(date=1700, prop=0.14, func="poss"), nudge_x=50, nudge_y=-0.05, size=labelsize, aes(label=func))

print(p)
ggsave("test.pdf", height=4, width=6)
