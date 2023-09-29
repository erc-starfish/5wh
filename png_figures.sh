#!/bin/bash

convert -density 600x600 number/Figure1.pdf -quality 90 figures/Figure1.png
convert -density 600x600 null-subjects/Figure2.pdf -quality 90 figures/Figure2.png
convert -density 600x600 null-subjects/Figure3.pdf -quality 90 figures/Figure3.png
convert -density 600x600 "case/Figure4.pdf" -quality 90 figures/Figure4.png
convert -density 600x600 "case/Figure5.pdf" -quality 90 figures/Figure5.png
