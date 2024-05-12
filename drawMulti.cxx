TH1F * DrawOverflow(TH1F *h) {
  // This function paint the histogram h with an extra bin for overflows
  UInt_t nx = h->GetNbinsX()+1;
  Double_t *xbins= new Double_t[nx+1];
  for (UInt_t i=0;i<nx;i++)
    xbins[i]=h->GetBinLowEdge(i+1);
  xbins[nx]=xbins[nx-1]+h->GetBinWidth(nx);
  char *tempName= new char[strlen(h->GetName())+10];
  sprintf(tempName,"%swtOverFlow",h->GetName());
  // Book a temporary histogram having ab extra bin for overflows
  TH1F *htmp = new TH1F(tempName, h->GetTitle(), nx, xbins);
  //---- style
  htmp->SetLineColor(h->GetLineColor());
  htmp->SetLineWidth(h->GetLineWidth());
  htmp->SetLineStyle(h->GetLineStyle());
  // Reset the axis labels
  htmp->SetXTitle(h->GetXaxis()->GetTitle());
  htmp->SetYTitle(h->GetYaxis()->GetTitle());
  // Fill the new hitogram including the extra bin for overflows
  for (UInt_t i=1; i<=nx; i++)
    htmp->Fill(htmp->GetBinCenter(i), h->GetBinContent(i));
  // Fill the underflows
  htmp->Fill(h->GetBinLowEdge(1)-1, h->GetBinContent(0));
  // Restore the number of entries
  htmp->SetEntries(h->GetEntries());
  // FillStyle and color
  htmp->SetFillStyle(h->GetFillStyle());
  htmp->SetFillColor(h->GetFillColor());
  return htmp;
}

#include "TDRStyle.cc"

void drawMulti(std::string nameInFileRootOne, 
          std::string nameInFileRootTwo, 
          std::string nameInFileRootThree,
          std::string nameInFileRoot4, 
          std::string nameInFileRoot5,
          std::string nameInFileRoot6, 
          std::string nameInFileRoot7, 
          std::string nameInFileRoot8, 
 
          std::string var = "pt1", int NBIN = 200, float MIN = 0, float MAX = 500, std::string varHR = ""
          ) {
  
   
  TDRStyle();
  gStyle->SetTitleYOffset(1.1);
  gStyle->cd();
  
  if (varHR == "") {
    varHR = var;
  }
  gStyle->SetOptStat(0);
  
  
  TFile* f_1;
  TFile* f_2;
  TFile* f_3;
  TFile* f_4;
  TFile* f_5; 
  TFile* f_6;
  TFile* f_7;
  TFile* f_8;    

  f_1 = new TFile (nameInFileRootOne.c_str());
  f_2 = new TFile (nameInFileRootTwo.c_str());
  f_3 = new TFile (nameInFileRootThree.c_str());
  f_4 = new TFile (nameInFileRoot4.c_str());         
  f_5 = new TFile (nameInFileRoot5.c_str());
  f_6 = new TFile (nameInFileRoot6.c_str());
  f_7 = new TFile (nameInFileRoot7.c_str());
  f_8 = new TFile (nameInFileRoot8.c_str());



  TTree* t_1;
  TTree* t_2;
  TTree* t_3;
  TTree* t_4; 
  TTree* t_5;    
  TTree* t_6;
  TTree* t_7;
  TTree* t_8;
   
  t_1 = (TTree*) f_1 -> Get ("tree");
  t_2 = (TTree*) f_2 -> Get ("tree");
  t_3 = (TTree*) f_3 -> Get ("tree");
  t_4 = (TTree*) f_4 -> Get ("tree");
  t_5 = (TTree*) f_5 -> Get ("tree");
  t_6 = (TTree*) f_6 -> Get ("tree");
  t_7 = (TTree*) f_7 -> Get ("tree");
  t_8 = (TTree*) f_8 -> Get ("tree");

  TH1F* h_1;
  TH1F* h_2;
  TH1F* h_3;
  TH1F* h_4;  
  TH1F* h_5; 
  TH1F* h_6;  
  TH1F* h_7;  
  TH1F* h_8;   

  h_1 = new TH1F("h_1","(0.001,0.1)",NBIN,MIN,MAX);
  h_2 = new TH1F("h_2","(0.001,1)",NBIN,MIN,MAX);
  h_3 = new TH1F("h_3","(1,0.1)",NBIN,MIN,MAX);
  h_4 = new TH1F("h_4","(1,1)",NBIN,MIN,MAX);
  h_5 = new TH1F("h_5","2.0",NBIN,MIN,MAX);       
  h_6 = new TH1F("h_6","2.0",NBIN,MIN,MAX);   
  h_7 = new TH1F("h_7","2.0",NBIN,MIN,MAX);   
  h_8 = new TH1F("h_8","2.0",NBIN,MIN,MAX);   

  h_1->Sumw2();
  h_2->Sumw2();
  h_3->Sumw2();            
  h_4->Sumw2();
  h_5->Sumw2(); 
  h_6->Sumw2(); 
  h_7->Sumw2(); 
  h_8->Sumw2(); 
  TString weight = Form ("evtWeight");
//   TString weight = Form ("1");
  TString toDraw;
   
  toDraw = Form ("%s >> h_1",var.c_str());
  t_1->Draw(toDraw.Data());

  toDraw = Form ("%s >> h_2",var.c_str());
  t_2->Draw(toDraw.Data());

  toDraw = Form ("%s >> h_3",var.c_str());
  t_3->Draw(toDraw.Data());

  toDraw = Form ("%s >> h_4",var.c_str());
  t_4->Draw(toDraw.Data());

  toDraw = Form ("%s >> h_5",var.c_str());
    t_5->Draw(toDraw.Data());
    
  toDraw = Form ("%s >> h_6",var.c_str());
    t_6->Draw(toDraw.Data());    

  toDraw = Form ("%s >> h_7",var.c_str());
    t_7->Draw(toDraw.Data());    

  toDraw = Form ("%s >> h_8",var.c_str());
    t_8->Draw(toDraw.Data());    


  //
  //---- the h_2 as drawn from ttree is the 
  //---- EWK correction to the Born production
  //
//   
//   h_2->Add(h_1);
//   
  //----
  
  
  h_1->SetMarkerSize  (0);
  h_1->SetMarkerColor (kBlue);
  h_1->SetLineColor   (kBlue);
  
  h_2->SetMarkerSize  (0);
  h_2->SetMarkerColor (kRed);
  h_2->SetLineColor   (kRed);

  h_3->SetMarkerSize  (0);
  h_3->SetMarkerColor (kGreen+1);
  h_3->SetLineColor   (kGreen+1); 

  h_4->SetMarkerSize  (0);
  h_4->SetMarkerColor (kBlack);
  h_4->SetLineColor   (kBlack); 

  h_5->SetMarkerSize  (0);
  h_5->SetMarkerColor (kCyan);
  h_5->SetLineColor   (kCyan); 

  h_6->SetMarkerSize  (0);
  h_6->SetMarkerColor (kOrange);
  h_6->SetLineColor   (kOrange); 
  h_7->SetMarkerSize  (0);
  h_7->SetMarkerColor (kYellow);
  h_7->SetLineColor   (kYellow); 

  h_8->SetMarkerSize  (0);
  h_8->SetMarkerColor (kMagenta);
  h_8->SetLineColor   (kMagenta); 


  h_1->SetLineWidth(3);
  h_2->SetLineWidth(3);
  h_3->SetLineWidth(3); 
  h_4->SetLineWidth(3); 
  h_5->SetLineWidth(3);
  h_6->SetLineWidth(3);
  h_7->SetLineWidth(3);
  h_8->SetLineWidth(3);


  h_1->GetXaxis()->SetTitle(varHR.c_str());
  h_2->GetXaxis()->SetTitle(varHR.c_str());
  h_3->GetXaxis()->SetTitle(varHR.c_str());
  h_4->GetXaxis()->SetTitle(varHR.c_str());
  h_5->GetXaxis()->SetTitle(varHR.c_str());
  h_6->GetXaxis()->SetTitle(varHR.c_str());  
  h_7->GetXaxis()->SetTitle(varHR.c_str());  
  h_8->GetXaxis()->SetTitle(varHR.c_str());  
  TLegend* leg = new TLegend(0.80,0.70,0.95,0.90);
  leg->AddEntry(h_1, "NLOWW", "l");
  leg->AddEntry(h_2, "ALPWW", "l");
  leg->AddEntry(h_3, "NLOZZ", "l");
  leg->AddEntry(h_4, "ALPZZ", "l");
  leg->AddEntry(h_5, "NLOW+Z", "l");
  leg->AddEntry(h_6, "ALPW+Z", "l");
  leg->AddEntry(h_7, "NLOW-Z", "l");
  leg->AddEntry(h_8, "ALPW-Z", "l");
  //leg->AddEntry(h_3, h_3->GetTitle(), "l");
  //leg->AddEntry(h_4, h_4->GetTitle(), "l");    
  //leg->AddEntry(h_5, h_5->GetTitle(), "l");

  leg->SetFillStyle(0);

  //---- overflow bin
  h_1 = DrawOverflow(h_1);
  h_2 = DrawOverflow(h_2);
  h_3 = DrawOverflow(h_3);
  h_4 = DrawOverflow(h_4); 
  h_5 = DrawOverflow(h_5); 
  h_6 = DrawOverflow(h_6); 
  h_7 = DrawOverflow(h_7); 
  h_8 = DrawOverflow(h_8); 


  //---- draw
  TCanvas* cn = new TCanvas ("cn","cn",800,600);
  
  h_1->Draw("hist");
  h_2->Draw("hist same");
  h_3->Draw("hist same"); 
  h_4->Draw("hist same"); 
  h_5->Draw("hist same"); 
  h_6->Draw("hist same"); 
  h_7->Draw("hist same"); 
  h_8->Draw("hist same"); 
  leg->Draw();
  cn->SetGrid();

  //---- draw
  TCanvas* cnNorm = new TCanvas ("cnNorm","cnNorm",800,600);
  
  h_1->DrawNormalized("hist");
  h_2->DrawNormalized("hist same");
  h_3->DrawNormalized("hist same");  
  h_4->DrawNormalized("hist same");  
  h_5->DrawNormalized("hist same");  
  h_6->DrawNormalized("hist same"); 
  h_7->DrawNormalized("hist same"); 
  h_8->DrawNormalized("hist same"); 

  leg->Draw(); 
  cnNorm->SetGrid(); 

  
  //---- draw ratio
  //  TCanvas* cnRatio = new TCanvas ("cnRatio","cnRatio",800,600);
  
  // Define the ratio plot
  //TH1F *h_ratio  = (TH1F*) h_2->Clone("h_ratio");
  //h_ratio->GetYaxis()->SetTitle("after / before");
  //h_ratio->SetLineColor(kBlack);
  //h_ratio->SetStats(0);     
  //h_ratio->Divide(h_1);
  //h_ratio->SetMarkerStyle(21);
  //h_ratio->Draw("histo");      
  
  
}
