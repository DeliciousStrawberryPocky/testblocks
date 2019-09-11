/* -*- c++ -*- */
/* 
 * Copyright 2019 gr-Receivers author.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_RECEIVERS_FLL_BAND_EDGE_MODIFIED_CC_IMPL_H
#define INCLUDED_RECEIVERS_FLL_BAND_EDGE_MODIFIED_CC_IMPL_H

#include <Receivers/fll_band_edge_modified_cc.h>
#include <Receivers/control_loop.h>
#include <gnuradio/filter/fir_filter_with_buffer.h>

namespace gr {
  namespace Receivers {

    class fll_band_edge_modified_cc_impl : public fll_band_edge_modified_cc
    {


     private:
        float                   d_sps;
        float                   d_rolloff;
        int                     d_filter_size;

        std::vector<gr_complex> d_taps_lower;
        std::vector<gr_complex> d_taps_upper;
        bool          d_updated;
        gr::filter::kernel::fir_filter_with_buffer_ccc* d_filter_lower;
        gr::filter::kernel::fir_filter_with_buffer_ccc* d_filter_upper;

        /*!
         * Design the band-edge filter based on the number of samples
         * per symbol, filter rolloff factor, and the filter size
         *
         * \param samps_per_sym    (float) Number of samples per symbol of signal
         * \param rolloff          (float) Rolloff factor of signal
         * \param filter_size      (int)   Size (in taps) of the filter
         */
        void design_filter(float samps_per_sym, float rolloff, int filter_size);

      public:
        fll_band_edge_modified_cc_impl(float samps_per_sym, float rolloff,
           int filter_size, float bandwidth);
        ~fll_band_edge_modified_cc_impl();

        void set_samples_per_symbol(float sps);
        void set_rolloff(float rolloff);
        void set_filter_size(int filter_size);

        float samples_per_symbol() const;
        float rolloff() const;
        int filter_size() const;


        void print_taps();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace Receivers
} // namespace gr

#endif /* INCLUDED_RECEIVERS_FLL_BAND_EDGE_MODIFIED_CC_IMPL_H */

