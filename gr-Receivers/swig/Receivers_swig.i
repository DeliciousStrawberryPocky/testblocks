/* -*- c++ -*- */

#define RECEIVERS_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "Receivers_swig_doc.i"

%{
#include "Receivers/fll_band_edge_modified_cc.h"
#include "Receivers/control_loop.h"
%}

%include "Receivers/fll_band_edge_modified_cc.h"
GR_SWIG_BLOCK_MAGIC2(Receivers, fll_band_edge_modified_cc);
%include "Receivers/control_loop.h"
