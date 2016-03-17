#########
### Latex

%.pdf: %.ps
	ps2pdf $<

%.ps: %.dvi
	dvips -Ppdf $< -o $@

%.rtf: %.tex
	latex2rtf -o $@ $<

%.dvi: %.tex
	latex $<

%.eps: %.dia
	dia --nosplash -e $@ $<


cleantex:
	rm -f *~ *.dvi *.log *.aux

cleanps: cleantex
	rm -f *.ps

