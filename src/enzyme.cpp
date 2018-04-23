//
// Created by Katherine Ritchie on 4/18/18.
//

#include "enzyme.h"

Enzyme::Enzyme() {
    name_ = "";
    reactions_ = std::vector<Reaction>();
}
Enzyme::Enzyme(std::vector<Reaction> rxn_v) {
    reactions_ = rxn_v;
}

std::string Enzyme::GetName() {
    return name_;
}

std::vector<Reaction> Enzyme::GetReactions() {
    return reactions_;
}