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


#ifndef INCLUDED_RECEIVERS_FLL_BAND_EDGE_MODIFIED_CC_H
#define INCLUDED_RECEIVERS_FLL_BAND_EDGE_MODIFIED_CC_H

#include <Receivers/api.h>
#include <gnuradio/sync_block.h>
#include <Receivers/control_loop.h>


namespace gr {
  namespace Receivers {

    /*!
     * \brief <+description of block+>
     * \ingroup Receivers
     *
     */
    class RECEIVERS_API fll_band_edge_modified_cc : virtual public gr::sync_block, virtual public control_loop
    {
     public:
      typedef boost::shared_ptr<fll_band_edge_modified_cc> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of Receivers::fll_band_edge_modified_cc.
       *
       * To avoid accidental use of raw pointers, Receivers::fll_band_edge_modified_cc's
       * constructor is in a private implementation
       * class. Receivers::fll_band_edge_modified_cc::make is the public interface for
       * creating new instances.
       */
      static sptr make(float samps_per_sym, float rolloff,
           int filter_size, float bandwidth);

      virtual void set_samples_per_symbol(float sps) = 0;

      virtual void set_rolloff(float rolloff) = 0;

      virtual void set_filter_size(int filter_size) = 0;

      virtual float samples_per_symbol() const = 0;

      virtual float rolloff() const = 0;

      virtual int filter_size() const = 0;

      virtual void print_taps() = 0;
    };

  } // namespace Receivers
} // namespace gr

#endif /* INCLUDED_RECEIVERS_FLL_BAND_EDGE_MODIFIED_CC_H */

