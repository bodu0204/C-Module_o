#include "Span.hpp"

Span::Span(): data_(NULL), N_(0) {}

Span::Span(const uint32 n): data_(new std::vector<int>(0)), N_(n) {}

Span::Span(const Span& copy): data_(NULL) { *this = copy; }

Span& Span::operator = (const Span& a) {
	delete data_;

	N_ = a.N_;
	data_ = new std::vector<int>(0);
	this->addNumbers(*a.data_);
	return *this;
}

Span::~Span(){ delete data_; }

void Span::addNumber(const int n) {
	if (data_->size() >= N_)
		throw std::range_error("Already filled.\n");
	data_->push_back(n);
}

void Span::addNumbers(const std::vector<int> v) {
	if (v.size() > N_)
		throw std::range_error("Size of vector is out of range");
	for (uint32 i=0; i < v.size(); i++) {
		data_->push_back(v.at(i));
	}
} 

uint32 Span::shortestSpan() const {
	std::vector<int> tmp = *data_;

	std::sort(tmp.begin(), tmp.end());

	uint32 span = std::numeric_limits<uint32>::max();

	for (uint32 i=0; i+1 < tmp.size(); i++) {
		span = std::min<uint32>(span, (tmp.at(i + 1) - tmp.at(i)));
	}
	return span;
}

int64 Span::longestSpan() const {
	if (data_->size() < 2)
		throw std::runtime_error("There are not enough numbers.");
	int min = *std::min_element(data_->begin(), data_->end());
	int max = *std::max_element(data_->begin(), data_->end());

	return static_cast<int64>(max) - static_cast<int64>(min);
}

void Span::put(std::ostream& ost) const {
	for (uint32 i=0; i < data_->size(); i++) {
		ost << data_->at(i) << ",";
	}
}

std::ostream& operator << (std::ostream& ost, const Span& s) {
	s.put(ost);
	return ost;
}
