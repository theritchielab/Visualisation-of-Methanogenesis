#include "metabolite.h"
#include <math.h>

////copy constructor
//Metabolite::Metabolite(const Metabolite& source) {
//    fullname_ = source.GetFullname();
//    shortname_ = source.GetShortname();
//    num_particles_ = source.GetNumParticles();
//    x_pos_ = source.GetXPos();
//    y_pos_ = source.GetYPos();
//}
//
////move constructor
//Metabolite::Metabolite(Metabolite&& source) noexcept {
//    if (this == &source) {
//        return;
//    }
//
//    fullname_ = source.GetFullname();
//    shortname_ = source.GetShortname();
//    num_particles_ = source.GetNumParticles();
//    x_pos_ = source.GetXPos();
//    y_pos_ = source.GetYPos();
//
////    if (source.GetFullname()) {
////        source.SetFullName("");
////    }
////    if (source.GetShortname()) {
////        source.SetShortName("");
////    }
//    if (source.GetNumParticles()) {
//        source.SetNumParticles(0);
//    }
//    if (source.GetXPos()) {
//        source.SetXPos(0);
//    }
//    if (source.GetYPos()) {
//        source.SetYPos(0);
//    }
//}

//destructor
Metabolite::~Metabolite() {
    //TODO if an object only contain two strings and an int.... do you need to write anything in the destructor???
////    if (fullname_) {
////        delete  &fullname_;
////    }
////    if (shortname_) {
////        delete &shortname_;
////    }
//    if (num_particles_) {
//        delete num_particles_;
//    }
//    if (x_pos_) {
//        delete x_pos_;
//    }
//    if (y_pos_) {
//        delete y_pos_;
//    }
}

std::string Metabolite::GetFullname() const {
    return fullname_;
}

std::string Metabolite::GetShortname() const {
    return shortname_;
}

long Metabolite::GetNumParticles() const {
    return num_particles_;
}

int Metabolite::GetXPos() const {
    return x_pos_;
}

int Metabolite::GetYPos() const {
    return y_pos_;
}

void Metabolite::SetFullName(std::string fullname_v) {
    fullname_ = fullname_v;
}

void Metabolite::SetShortName(std::string shortname_v) {
    shortname_ = shortname_v;
}

void Metabolite::SetNumParticles(double init_conc_v, double volume_v, std::string units) {
    num_particles_ = ConcToNumParticles(init_conc_v, volume_v);
}

void Metabolite::SetNumParticles(long num_particles_v) {
    num_particles_ = num_particles_v;
}

void Metabolite::SetXPos(int x_pos_v) {
    x_pos_ = x_pos_v;
}
void Metabolite::SetYPos(int y_pos_v) {
    y_pos_ = y_pos_v;
}

void Metabolite::rm_particle() {
    if (num_particles_ == 0) {
        return;
    }
    num_particles_ = num_particles_ - (long) 1;
}

void Metabolite::add_particle() {
    num_particles_ = num_particles_ + (long) 1;
}

bool Metabolite::operator==(const Metabolite &rhs) const {
    if (shortname_ != rhs.GetShortname()) {
        return false;
    }
    if (fullname_ != rhs.GetFullname()) {
        return false;
    }
    if (num_particles_ != rhs.GetNumParticles()) {
        return false;
    }
    //TODO double check that this is the right design choice!!!!!!
    //we do not check for x/y positions as there may be multiple representations of the same chemical
    return true;
}

bool Metabolite::operator!=(const Metabolite &rhs) const {
    return !(*this == rhs);
}

long ConcToNumParticles(double conc, double numfL) {
    return (long) (pow(10.0, 23) * pow(10.0, -15) * (double) (conc * 6.023 * numfL));
}