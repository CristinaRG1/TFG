# TFG



--------------------
ntupleMaker_cuts.cpp
--------------------
This analysis routine applies selection cuts for studying the production of WW, ZZ, and WZ dibosons with leptonic decays. Firstly, a restriction is applied to the invariant mass of all lepton pairs: events with an OSSF lepton pair invariant mass below 4 GeV are excluded. For lepton pairs decaying from a Z boson, an invariant mass range of 60 < m(ll´) < 120 GeV is imposed for the ZZ and WZ cases, to ensure on-shell Z boson production under resonance conditions.


--------------------
ntupleMaker_strongcuts.cpp
--------------------

This ROOT analysis code imposes specific restrictions to study the production of dibosons with leptonic decays, focusing on the WW case. The objective of the routine is to distinguish the signal from specific background processes, such as ttbar production. The selection criteria include: two tight opposite-sign different-flavor leptons with pT1 > 20 GeV and pT2 > 10 GeV, lepton system transverse momentum pT (ll) > 20 GeV, ∆φ(ll) > 2.8, and a transverse mass of the missing lepton and pTmiss pairs greater than 20 GeV (mT​(l1​,pmissT​),mT​(l2​,pT​)>20GeV).


--------------------
ntupleMaker_ALP.cpp
--------------------
This analysis routine applies selection cuts to analyze the ALP signal and distinguish it from the background, specifically from the production of WW dibosons with leptonic decays at NLO. Moreover, several variables are implemented to display their distributions and compare the signal versus the background, including the missing transverse momentum from the neutrinos, the transverse mass of the lepton pairs, the transverse mass of the system formed by the least energetic W boson lepton (second lepton) and the ptmiss, the angle difference ∆φ(ll) between the two leptons, and the transverse momentum of the lepton pairs, among others.

