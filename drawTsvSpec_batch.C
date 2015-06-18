// Introduction: we take spectra with SPECTECH UCS20 Multi Channel Analyzer with its offical software.
//               the default saved spectrum files (*.spu) can be again saved as *.tsv files (tab seperated file).
//               the *.tsv files can be read by this script and so that better spectra can be histogrammed with ROOT.
//  -> This script can handle either one or more *.tsv files.
// Author: Aiwu Zhang
//
#include <TString>
void drawOneSpectrumTSV(string thefile){
	string filename = thefile+".tsv";
  string hTitle = thefile;
  string rootfile = thefile+".root";
  fstream fin(filename.c_str(),ios::in);
  string lineContent;
  TString theTimeString;

  double time=0;
  for(int i=0;i<22;i++){
    getline(fin,lineContent);
    if(lineContent.substr(0,43)=="Calibration Coefficients:Elapsed Real Time:"){
    	theTimeString=lineContent.substr(44);
    	time=theTimeString.Atof();
    	//cout<<time<<"\t"<<time/100<<endl;
    }
  }
  
  TH1F* hist = new TH1F(hTitle.c_str(),"",2048,0,2048);
  int bin=0;
  float number=0;
  int count=0;
  while(fin>>bin>>number){
    hist->SetBinContent(bin,number/time);
    count+=number;
  }
  fin.close();
  
  hist->SetXTitle("ADC count");
  hist->SetYTitle("Counts per bin per second");
  hist->SetTitleSize(0.04,"XY");
  hist->SetLabelSize(0.04,"XY");
  hist->SetEntries(count);
  TCanvas* c = new TCanvas();
  hist->Draw();
  //hist->SaveAs(rootfile.c_str());
  hist->Write();
  c->Close();
}

void main(){
	TFile* f = new TFile("SpectraData.root","recreate");
	string files[]={
         "20150618_unKnownSource_PMT1.1kV_ampGain50"
		};
			
	
	for(int i=0;i<1;i++){
	  cout<<files[i]<<endl;
	  drawOneSpectrumTSV(files[i]);
	}
}
