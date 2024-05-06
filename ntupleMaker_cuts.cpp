#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <assert.h>

#include "LHEF.h"

#include "TTree.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "Math/Vector3D.h"
#include "Math/Vector4D.h"

#include "TRandom.h"

struct ptsort: public std::binary_function<TLorentzVector, TLorentzVector, bool> {
  bool operator () (const TLorentzVector & x, const TLorentzVector & y) {
    return (x.Perp () < y.Perp () ) ;
  }
} ;

TLorentzVector buildP (const LHEF::HEPEUP & event, int iPart) {
  TLorentzVector dummy ;
  dummy.SetPxPyPzE (
    event.PUP.at (iPart).at (0), // px
                    event.PUP.at (iPart).at (1), // py
                    event.PUP.at (iPart).at (2), // pz
                    event.PUP.at (iPart).at (3) // E
  ) ;
  return dummy ;
}




class myParticle {
  
public:
  
  myParticle() {};
  
  virtual ~myParticle(){};
  
  myParticle( const TLorentzVector & p4):
  p4_(p4){}
  
  myParticle( const myParticle& other ) : p4_( other.p4_) {
    pdgId_ = other.GetPdgId();
  }
  
  bool operator < (const myParticle & other) const {
    if( p4_.Pt() < other.p4_.Pt()) 
      return true;
    else return false;
  }
  
  void SetPdgId(int pdgId) {
    pdgId_ = pdgId;
  }
  
  int GetPdgId() const {
    return pdgId_;
  }
  
  TLorentzVector GetP4(){ 
    return p4_;
  }
  
  
private :
  TLorentzVector p4_;
  int pdgId_;
  
};



class myTree {
  
public:
  
  myTree();
  ~myTree() {};
  
  TTree* tree;
  
  float _evtWeight;
  
  float _mww;
  float _ptww;
  
  float ptl1_;
  float etal1_;
  float phil1_;
  float ml1_;
  int   pdgIdl1_;
  
  float ptl2_;
  float etal2_;
  float phil2_;
  float ml2_;
  int   pdgIdl2_;
  
  float ptl3_;
  float etal3_;
  float phil3_;
  float ml3_;
  int   pdgIdl3_;
  
  float ptl4_;
  float etal4_;
  float phil4_;
  float ml4_;
  int   pdgIdl4_;
  
  float ptq1_;
  float etaq1_;
  float phiq1_;
  float mq1_;
  int   pdgIdq1_;
  
  float ptq2_;
  float etaq2_;
  float phiq2_;
  float mq2_;
  int   pdgIdq2_;
  
  float _mqq;
  
  
  float ptq3_;
  float etaq3_;
  float phiq3_;
  float mq3_;
  int   pdgIdq3_;
  
  float ptq4_;
  float etaq4_;
  float phiq4_;
  float mq4_;
  int   pdgIdq4_;
  
  float ptnu1_;
  float etanu1_;
  float phinu1_;
  float mnu1_;
  int   pdgIdnu1_;
  
  float ptnu2_;
  float etanu2_;
  float phinu2_;
  float mnu2_;
  int   pdgIdnu2_;
  
  float ptv1_;
  float etav1_;
  float phiv1_;
  float mv1_;
  int   pdgIdv1_;
  
  float ptv2_;
  float etav2_;
  float phiv2_;
  float mv2_;
  int   pdgIdv2_;
  
  float pth1_;
  float etah1_;
  float phih1_;
  float mh1_;
  int   pdgIdh1_;
  
  void fillTree (std::string fileNameLHE);
  void Write(TFile& out);
  void Init();
  
};


myTree::myTree(){
  tree = new TTree("tree","tree");
  
  tree = new TTree("tree","tree");
  
  tree->Branch("evtWeight",&_evtWeight,"evtWeight/F");
  
  tree->Branch("mww",&_mww,"mww/F");
  tree->Branch("ptww",&_ptww,"ptww/F");
  
  tree->Branch("ptl1",&ptl1_,"ptl1/F");
  tree->Branch("etal1",&etal1_,"etal1/F");
  tree->Branch("phil1",&phil1_,"phil1/F");
  tree->Branch("ml1",&ml1_,"ml1/F");
  tree->Branch("pdgIdl1",&pdgIdl1_,"pdgIdl1/I");
  
  tree->Branch("ptl2",&ptl2_,"ptl2/F");
  tree->Branch("etal2",&etal2_,"etal2/F");
  tree->Branch("phil2",&phil2_,"phil2/F");
  tree->Branch("ml2",&ml2_,"ml2/F");
  tree->Branch("pdgIdl2",&pdgIdl2_,"pdgIdl2/I");
  
  tree->Branch("ptl3",&ptl3_,"ptl3/F");
  tree->Branch("etal3",&etal3_,"etal3/F");
  tree->Branch("phil3",&phil3_,"phil3/F");
  tree->Branch("ml3",&ml3_,"ml3/F");
  tree->Branch("pdgIdl3",&pdgIdl3_,"pdgIdl3/I");
  
  tree->Branch("ptl4",&ptl4_,"ptl4/F");
  tree->Branch("etal4",&etal4_,"etal4/F");
  tree->Branch("phil4",&phil4_,"phil4/F");
  tree->Branch("ml4",&ml4_,"ml4/F");
  tree->Branch("pdgIdl4",&pdgIdl4_,"pdgIdl4/I");
  
  ///
  tree->Branch("ptnu1",&ptnu1_,"ptnu1/F");
  tree->Branch("etanu1",&etanu1_,"etanu1/F");
  tree->Branch("phinu1",&phinu1_,"phinu1/F");
  tree->Branch("mnu1",&mnu1_,"mnu1/F");
  tree->Branch("pdgIdnu1",&pdgIdnu1_,"pdgIdnu1/I");
  
  tree->Branch("ptnu2",&ptnu2_,"ptnu2/F");
  tree->Branch("etanu2",&etanu2_,"etanu2/F");
  tree->Branch("phinu2",&phinu2_,"phinu2/F");
  tree->Branch("mnu2",&mnu2_,"mnu2/F");
  tree->Branch("pdgIdnu2",&pdgIdnu2_,"pdgIdnu2/I");
  
  ///
  tree->Branch("ptq1",&ptq1_,"ptq1/F");
  tree->Branch("etaq1",&etaq1_,"etaq1/F");
  tree->Branch("phiq1",&phiq1_,"phiq1/F");
  tree->Branch("mq1",&mq1_,"mq1/F");
  tree->Branch("pdgIdq1",&pdgIdq1_,"pdgIdq1/I");
  
  tree->Branch("ptq2",&ptq2_,"ptq2/F");
  tree->Branch("etaq2",&etaq2_,"etaq2/F");
  tree->Branch("phiq2",&phiq2_,"phiq2/F");
  tree->Branch("mq2",&mq2_,"mq2/F");
  tree->Branch("pdgIdq2",&pdgIdq2_,"pdgIdq2/I");
  
  tree->Branch("mqq",&_mqq,"mqq/F");
  
  
  tree->Branch("ptq3",&ptq3_,"ptq3/F");
  tree->Branch("etaq3",&etaq3_,"etaq3/F");
  tree->Branch("phiq3",&phiq3_,"phiq3/F");
  tree->Branch("mq3",&mq3_,"mq3/F");
  tree->Branch("pdgIdq3",&pdgIdq3_,"pdgIdq3/I");
  
  tree->Branch("ptq4",&ptq4_,"ptq4/F");
  tree->Branch("etaq4",&etaq4_,"etaq4/F");
  tree->Branch("phiq4",&phiq4_,"phiq4/F");
  tree->Branch("mq4",&mq4_,"mq4/F");
  tree->Branch("pdgIdq4",&pdgIdq4_,"pdgIdq4/I");
  
  ///
  tree->Branch("ptv1",&ptv1_,"ptv1/F");
  tree->Branch("etav1",&etav1_,"etav1/F");
  tree->Branch("phiv1",&phiv1_,"phiv1/F");
  tree->Branch("mv1",&mv1_,"mv1/F");
  tree->Branch("pdgIdv1",&pdgIdv1_,"pdgIdv1/I");
  
  tree->Branch("ptv2",&ptv2_,"ptv2/F");
  tree->Branch("etav2",&etav2_,"etav2/F");
  tree->Branch("phiv2",&phiv2_,"phiv2/F");
  tree->Branch("mv2",&mv2_,"mv2/F");
  tree->Branch("pdgIdv2",&pdgIdv2_,"pdgIdv2/I");
  
  ///
  tree->Branch("pth1",&pth1_,"pth1/F");
  tree->Branch("etah1",&etah1_,"etah1/F");
  tree->Branch("phih1",&phih1_,"phih1/F");
  tree->Branch("mh1",&mh1_,"mh1/F");
  tree->Branch("pdgIdh1",&pdgIdh1_,"pdgIdh1/I");
  
}

void myTree::Init(){
  
  _evtWeight = 1.;
  
  _mww = -99;
  _ptww = -99;
  
  ptl1_= -99;
  etal1_= -99;
  phil1_= -99;
  ml1_= -99;
  pdgIdl1_= -99;
  
  ptl2_= -99;
  etal2_= -99;
  phil2_= -99;
  ml2_= -99;
  pdgIdl2_= -99;
  
  ptl3_= -99;
  etal3_= -99;
  phil3_= -99;
  ml3_= -99;
  pdgIdl3_= -99;
  
  ptl4_= -99;
  etal4_= -99;
  phil4_= -99;
  ml4_= -99;
  pdgIdl4_= -99;
  
  ptq1_= -99;
  etaq1_= -99;
  phiq1_= -99;
  mq1_= -99;
  pdgIdq1_= -99;
  
  ptq2_= -99;
  etaq2_= -99;
  phiq2_= -99;
  mq2_= -99;
  pdgIdq2_= -99;
  
  _mqq = -99.;
  
  ptq3_= -99;
  etaq3_= -99;
  phiq3_= -99;
  mq3_= -99;
  pdgIdq3_= -99;
  
  ptq4_= -99;
  etaq4_= -99;
  phiq4_= -99;
  mq4_= -99;
  pdgIdq4_= -99;
  
  ptnu1_= -99;
  etanu1_= -99;
  phinu1_= -99;
  mnu1_= -99;
  pdgIdnu1_= -99;
  
  ptnu2_= -99;
  etanu2_= -99;
  phinu2_= -99;
  mnu2_= -99;
  pdgIdnu2_= -99;
  
  ptv1_= -99;
  etav1_= -99;
  phiv1_= -99;
  mv1_= -99;
  pdgIdv1_= -99;
  
  ptv2_= -99;
  etav2_= -99;
  phiv2_= -99;
  mv2_= -99;
  pdgIdv2_= -99;
  
  pth1_= -99;
  etah1_= -99;
  phih1_= -99;
  mh1_= -99;
  pdgIdh1_= -99;
  
}


void myTree::fillTree(std::string fileNameLHE){
  std::ifstream ifs(fileNameLHE.c_str());
  LHEF::Reader reader(ifs);
  
  long ieve = 0;
  long selected = 0;
  
  std::cout << "reading " << fileNameLHE << std::endl;

  // Antes del bucle
  long eventsPassingCuts = 0;
  
  while (reader.readEvent()) {
    ieve++;
    if (ieve % 10000 == 0) std::cout << "event " << ieve << std::endl;
    
    // Initialize variables in tree
    Init();
    
    // Get the event weight
    _evtWeight = reader.hepeup.XWGTUP;
    if (ieve % 10000 == 0)  std::cout << "   >> XWGTUP = " << _evtWeight << std::endl;
    
    // Initialize vectors for particles
    std::vector<myParticle> v_tlv_all_leptons; // leptons
    std::vector<myParticle> v_tlv_all_quarks; // quarks and gluons
    std::vector<myParticle> v_tlv_all_neutrinos; // neutrinos
    std::vector<myParticle> v_tlv_all_vbosons; // vector bosons
    std::vector<myParticle> v_tlv_all_hbosons; // higgs bosons
    
    // Loop over particles in the event and fill the variables of leptons and quarks
    for (size_t iPart = 0; iPart < reader.hepeup.IDUP.size(); ++iPart) {
      // Outgoing particles
      if (reader.hepeup.ISTUP.at(iPart) == 1 || reader.hepeup.ISTUP.at(iPart) == 2) {
        // Leptons
        if (abs(reader.hepeup.IDUP.at(iPart)) == 11 || abs(reader.hepeup.IDUP.at(iPart)) == 13 || abs(reader.hepeup.IDUP.at(iPart)) == 15) {
         // TLorentzvector (px,py,pz,E)
          TLorentzVector dummy(reader.hepeup.PUP.at(iPart).at(0), reader.hepeup.PUP.at(iPart).at(1), reader.hepeup.PUP.at(iPart).at(2), reader.hepeup.PUP.at(iPart).at(3));
          myParticle myPart(dummy);
          myPart.SetPdgId(reader.hepeup.IDUP.at(iPart));
          v_tlv_all_leptons.push_back(myPart);
        }
        // Neutrinos
        if (abs(reader.hepeup.IDUP.at(iPart)) == 12 || abs(reader.hepeup.IDUP.at(iPart)) == 14 || abs(reader.hepeup.IDUP.at(iPart)) == 16) {
          TLorentzVector dummy(reader.hepeup.PUP.at(iPart).at(0), reader.hepeup.PUP.at(iPart).at(1), reader.hepeup.PUP.at(iPart).at(2), reader.hepeup.PUP.at(iPart).at(3));
          myParticle myPart(dummy);
          myPart.SetPdgId(reader.hepeup.IDUP.at(iPart));
          v_tlv_all_neutrinos.push_back(myPart);
        }
        // Quarks and gluons
        if (abs(reader.hepeup.IDUP.at(iPart)) <= 5 || abs(reader.hepeup.IDUP.at(iPart)) == 21) {
          TLorentzVector dummy(reader.hepeup.PUP.at(iPart).at(0), reader.hepeup.PUP.at(iPart).at(1), reader.hepeup.PUP.at(iPart).at(2), reader.hepeup.PUP.at(iPart).at(3));
          myParticle myPart(dummy);
          myPart.SetPdgId(reader.hepeup.IDUP.at(iPart));
          v_tlv_all_quarks.push_back(myPart);
        }
        // Vector bosons
        if (abs(reader.hepeup.IDUP.at(iPart)) == 24 || abs(reader.hepeup.IDUP.at(iPart)) == 23) {
          TLorentzVector dummy(reader.hepeup.PUP.at(iPart).at(0), reader.hepeup.PUP.at(iPart).at(1), reader.hepeup.PUP.at(iPart).at(2), reader.hepeup.PUP.at(iPart).at(3));
          myParticle myPart(dummy);
          myPart.SetPdgId(reader.hepeup.IDUP.at(iPart));
          v_tlv_all_vbosons.push_back(myPart);
        }
        // Higgs bosons
        if (abs(reader.hepeup.IDUP.at(iPart)) == 25) {
          TLorentzVector dummy(reader.hepeup.PUP.at(iPart).at(0), reader.hepeup.PUP.at(iPart).at(1), reader.hepeup.PUP.at(iPart).at(2), reader.hepeup.PUP.at(iPart).at(3));
          myParticle myPart(dummy);
          myPart.SetPdgId(reader.hepeup.IDUP.at(iPart));
          v_tlv_all_hbosons.push_back(myPart);
        }
      } // Outgoing particles
    } // Loop over particles
    
    // Sort particles in pt
    sort(v_tlv_all_leptons.rbegin(), v_tlv_all_leptons.rend());
    sort(v_tlv_all_neutrinos.rbegin(), v_tlv_all_neutrinos.rend());
    sort(v_tlv_all_quarks.rbegin(), v_tlv_all_quarks.rend());
    sort(v_tlv_all_vbosons.rbegin(), v_tlv_all_vbosons.rend());
    sort(v_tlv_all_hbosons.rbegin(), v_tlv_all_hbosons.rend());
    
    
  // ---------------------------------------------------------------------------------------  
    

// Apply additional event selection criteria

// Exclude events with OSSF lepton pairs with invariant mass below 4 GeV
bool skipEvent = false;
for (size_t i = 0; i < v_tlv_all_leptons.size(); ++i) {
    for (size_t j = i + 1; j < v_tlv_all_leptons.size(); ++j) {
        if (v_tlv_all_leptons[i].GetPdgId() == -v_tlv_all_leptons[j].GetPdgId()) {
            double invMass = (v_tlv_all_leptons[i].GetP4() + v_tlv_all_leptons[j].GetP4()).M();
            if (invMass < 4.0) {
                skipEvent = true;
                break; // No need to continue if skipEvent is already true
            }
        }
    }
    if (skipEvent) break; // No need to continue if skipEvent is already true
}

// For ZZ regions, apply additional kinematic requirements
if (!skipEvent && v_tlv_all_leptons.size() == 4) {
    if ((v_tlv_all_leptons[0].GetPdgId() + v_tlv_all_leptons[1].GetPdgId() +
         v_tlv_all_leptons[2].GetPdgId() + v_tlv_all_leptons[3].GetPdgId()) == 0) { // ZZ region
        // Check all lepton pair combinations for ZZ region
        bool zzRegionPass = false;
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = i + 1; j < 4; ++j) {
                double mll = (v_tlv_all_leptons[i].GetP4() + v_tlv_all_leptons[j].GetP4()).M();
                if (mll >= 60.0 && mll <= 120.0) {
                    zzRegionPass = true;
                    break; // No need to continue checking if one pair passes
                }
            }
            if (zzRegionPass) break; // No need to continue checking if one pair passes
        }
        if (!zzRegionPass) skipEvent = true;
    }
}

// For WZ apply additional kinematic requirements
if (!skipEvent && v_tlv_all_leptons.size() == 3) {
    if (abs(v_tlv_all_leptons[0].GetPdgId() + v_tlv_all_leptons[1].GetPdgId() +
            v_tlv_all_leptons[2].GetPdgId()) == 11 || abs(v_tlv_all_leptons[0].GetPdgId() +
            v_tlv_all_leptons[1].GetPdgId() + v_tlv_all_leptons[2].GetPdgId()) == 13) { // WZ region
        // Check all lepton pair combinations for WZ region
        bool wzRegionPass = false;
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = i + 1; j < 3; ++j) {
                double mll = (v_tlv_all_leptons[i].GetP4() + v_tlv_all_leptons[j].GetP4()).M();
                if (mll >= 60.0 && mll <= 120.0) {
                    wzRegionPass = true;
                    break; // No need to continue checking if one pair passes
                }
            }
            if (wzRegionPass) break; // No need to continue checking if one pair passes
        }
        if (!wzRegionPass) skipEvent = true;
    }
}


	// Fill histograms only if the event passes all selection criteria
	if (!skipEvent) {



  // ---------------------------------------------------------------------------------------  
    
    // Fill the tree
    //---- fill the ntuple
    
    // leptons
    
    if (v_tlv_all_leptons.size()>0) {
      ptl1_  = v_tlv_all_leptons.at (0).GetP4().Pt ();
      etal1_ = v_tlv_all_leptons.at (0).GetP4().Eta ();
      phil1_ = v_tlv_all_leptons.at (0).GetP4().Phi ();
      ml1_   = v_tlv_all_leptons.at (0).GetP4().M ();
      pdgIdl1_ = v_tlv_all_leptons.at (0).GetPdgId ();
    }
    if (v_tlv_all_leptons.size()>1) {
      ptl2_  = v_tlv_all_leptons.at (1).GetP4().Pt ();
      etal2_ = v_tlv_all_leptons.at (1).GetP4().Eta ();
      phil2_ = v_tlv_all_leptons.at (1).GetP4().Phi ();
      ml2_   = v_tlv_all_leptons.at (1).GetP4().M ();
      pdgIdl2_ = v_tlv_all_leptons.at (1).GetPdgId ();
    }
    if (v_tlv_all_leptons.size()>2) {
      ptl3_  = v_tlv_all_leptons.at (2).GetP4().Pt ();
      etal3_ = v_tlv_all_leptons.at (2).GetP4().Eta ();
      phil3_ = v_tlv_all_leptons.at (2).GetP4().Phi ();
      ml3_   = v_tlv_all_leptons.at (2).GetP4().M ();
      pdgIdl3_ = v_tlv_all_leptons.at (2).GetPdgId ();
    }
    if (v_tlv_all_leptons.size()>3) {
      ptl4_  = v_tlv_all_leptons.at (3).GetP4().Pt ();
      etal4_ = v_tlv_all_leptons.at (3).GetP4().Eta ();
      phil4_ = v_tlv_all_leptons.at (3).GetP4().Phi ();
      ml4_   = v_tlv_all_leptons.at (3).GetP4().M ();
      pdgIdl4_ = v_tlv_all_leptons.at (3).GetPdgId ();
    }
    
    
    // quarks
    if (v_tlv_all_quarks.size()>0) {
      ptq1_  = v_tlv_all_quarks.at (0).GetP4().Pt ();
      etaq1_ = v_tlv_all_quarks.at (0).GetP4().Eta ();
      phiq1_ = v_tlv_all_quarks.at (0).GetP4().Phi ();
      mq1_   = v_tlv_all_quarks.at (0).GetP4().M ();
      pdgIdq1_ = v_tlv_all_quarks.at (0).GetPdgId ();
    }
    if (v_tlv_all_quarks.size()>1) {
      ptq2_  = v_tlv_all_quarks.at (1).GetP4().Pt ();
      etaq2_ = v_tlv_all_quarks.at (1).GetP4().Eta ();
      phiq2_ = v_tlv_all_quarks.at (1).GetP4().Phi ();
      mq2_   = v_tlv_all_quarks.at (1).GetP4().M ();
      pdgIdq2_ = v_tlv_all_quarks.at (1).GetPdgId ();
      
      _mqq = (v_tlv_all_quarks.at (0).GetP4() + v_tlv_all_quarks.at (1).GetP4()).M();
      
    }
    if (v_tlv_all_quarks.size()>2) {
      ptq3_  = v_tlv_all_quarks.at (2).GetP4().Pt ();
      etaq3_ = v_tlv_all_quarks.at (2).GetP4().Eta ();
      phiq3_ = v_tlv_all_quarks.at (2).GetP4().Phi ();
      mq3_   = v_tlv_all_quarks.at (2).GetP4().M ();
      pdgIdq3_ = v_tlv_all_quarks.at (2).GetPdgId ();
    }
    if (v_tlv_all_quarks.size()>3) {
      ptq4_  = v_tlv_all_quarks.at (3).GetP4().Pt ();
      etaq4_ = v_tlv_all_quarks.at (3).GetP4().Eta ();
      phiq4_ = v_tlv_all_quarks.at (3).GetP4().Phi ();
      mq4_   = v_tlv_all_quarks.at (3).GetP4().M ();
      pdgIdq4_ = v_tlv_all_quarks.at (3).GetPdgId ();
    }
    
    
    // neutrino
    if (v_tlv_all_neutrinos.size()>0) {
      ptnu1_  = v_tlv_all_neutrinos.at (0).GetP4().Pt ();
      etanu1_ = v_tlv_all_neutrinos.at (0).GetP4().Eta ();
      phinu1_ = v_tlv_all_neutrinos.at (0).GetP4().Phi ();
      mnu1_   = v_tlv_all_neutrinos.at (0).GetP4().M ();
      pdgIdnu1_ = v_tlv_all_neutrinos.at (0).GetPdgId ();
    }
    if (v_tlv_all_neutrinos.size()>1) {
      ptnu2_  = v_tlv_all_neutrinos.at (1).GetP4().Pt ();
      etanu2_ = v_tlv_all_neutrinos.at (1).GetP4().Eta ();
      phinu2_ = v_tlv_all_neutrinos.at (1).GetP4().Phi ();
      mnu2_   = v_tlv_all_neutrinos.at (1).GetP4().M ();
      pdgIdnu2_ = v_tlv_all_neutrinos.at (1).GetPdgId ();
    }
    
    
    // vbosons
    if (v_tlv_all_vbosons.size()>0) {
      ptv1_  = v_tlv_all_vbosons.at (0).GetP4().Pt ();
      etav1_ = v_tlv_all_vbosons.at (0).GetP4().Eta ();
      phiv1_ = v_tlv_all_vbosons.at (0).GetP4().Phi ();
      mv1_   = v_tlv_all_vbosons.at (0).GetP4().M ();
      pdgIdv1_ = v_tlv_all_vbosons.at (0).GetPdgId ();
    }
    if (v_tlv_all_vbosons.size()>1) {
      ptv2_  = v_tlv_all_vbosons.at (1).GetP4().Pt ();
      etav2_ = v_tlv_all_vbosons.at (1).GetP4().Eta ();
      phiv2_ = v_tlv_all_vbosons.at (1).GetP4().Phi ();
      mv2_   = v_tlv_all_vbosons.at (1).GetP4().M ();
      pdgIdv2_ = v_tlv_all_vbosons.at (1).GetPdgId ();
      
      _mww  = (v_tlv_all_vbosons.at (0).GetP4() + v_tlv_all_vbosons.at (1).GetP4() ).M();
      _ptww = (v_tlv_all_vbosons.at (0).GetP4() + v_tlv_all_vbosons.at (1).GetP4() ).Pt();
    }
    
    // hbosons
    if (v_tlv_all_hbosons.size()>0) {
      pth1_  = v_tlv_all_hbosons.at (0).GetP4().Pt ();
      etah1_ = v_tlv_all_hbosons.at (0).GetP4().Eta ();
      phih1_ = v_tlv_all_hbosons.at (0).GetP4().Phi ();
      mh1_   = v_tlv_all_hbosons.at (0).GetP4().M ();
      pdgIdh1_ = v_tlv_all_hbosons.at (0).GetPdgId ();
    }
    
    tree->Fill();
    eventsPassingCuts++; // Increment counter
  }
 } 
	
// After the loop, print the value of eventsPassingCuts
std::cout << "Number of events passing cuts: " << eventsPassingCuts << std::endl;

// Calculate the cross section after cuts
double _evtWeight_final = _evtWeight * (static_cast<double>(eventsPassingCuts) / ieve); // Calcular _evtWeight_final
// print the cross section after cuts
std::cout << "Cross section after cuts = " << _evtWeight_final << std::endl;  

}



void myTree::Write(TFile& out) {
  out.cd();
  tree->Write();
}



///---- LHE dumper ----

int main (int argc, char **argv) {
  // Open a stream connected to an event file:
  if (argc < 3) exit (1) ;
  
  std::cout << " Input LHE = " << argv[1] << std::endl;
  std::cout << " Output ROOT = " << argv[2] << std::endl;
  
  myTree myT;
  myT.fillTree (std::string(argv[1])) ;
  
  TFile output (argv[2], "recreate") ;
  output.cd() ;
  myT.Write(output);
  output.Close();
  
}
