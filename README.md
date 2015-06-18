# Scripts_Drawing_UCS20_Spectrum
The spectrum data from SpecTech UCS20 is formatted with ROOT and histograms are filled

(1) First save the *spu files that you obtained to *.tsv files. This can be done with the software that you are using to take spectra.

(2) The script will output a root file which contains the histogram(s) of the spectrum(a). At the end ther is a for loop which loops through the file names. The file names are put in an array. Remember to change the "***" in the for(int i=0;i<***;i++) if you have more than one file.

(3) The output histogram is normaliezed. The total time information that a spectrum is taken is recorded in the *tsv file. The script reads the information, basically a time (in seconds), and divids the entries of each bin by this time. So the Y axis of the output is: counts per bin per second !!
    If you don't want to do this, simply find in the script the place where the time is divided. Note there are two places, easy to be found!
    
(4) The histograms are not fitted with any function. You need to open the root file and fit histograms manually.
