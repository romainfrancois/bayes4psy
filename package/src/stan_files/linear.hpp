/*
    bayes4psy is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    bayes4psy is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with bayes4psy.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_linear_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_linear");
    reader.add_event(107, 105, "end", "model_linear");
    return reader;
}

#include <meta_header.hpp>
 class model_linear : public prob_grad {
private:
    int n;
    int m;
    vector_d x;
    vector_d y;
    vector<int> s;
    vector<int> p_ids;
    vector<double> p_values;
public:
    model_linear(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_linear(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_linear_namespace::model_linear";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "n", "int", context__.to_vec());
            n = int(0);
            vals_i__ = context__.vals_i("n");
            pos__ = 0;
            n = vals_i__[pos__++];
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "m", "int", context__.to_vec());
            m = int(0);
            vals_i__ = context__.vals_i("m");
            pos__ = 0;
            m = vals_i__[pos__++];
            current_statement_begin__ = 4;
            validate_non_negative_index("x", "n", n);
            context__.validate_dims("data initialization", "x", "vector_d", context__.to_vec(n));
            validate_non_negative_index("x", "n", n);
            x = vector_d(static_cast<Eigen::VectorXd::Index>(n));
            vals_r__ = context__.vals_r("x");
            pos__ = 0;
            size_t x_i_vec_lim__ = n;
            for (size_t i_vec__ = 0; i_vec__ < x_i_vec_lim__; ++i_vec__) {
                x[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 5;
            validate_non_negative_index("y", "n", n);
            context__.validate_dims("data initialization", "y", "vector_d", context__.to_vec(n));
            validate_non_negative_index("y", "n", n);
            y = vector_d(static_cast<Eigen::VectorXd::Index>(n));
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_i_vec_lim__ = n;
            for (size_t i_vec__ = 0; i_vec__ < y_i_vec_lim__; ++i_vec__) {
                y[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("s", "n", n);
            context__.validate_dims("data initialization", "s", "int", context__.to_vec(n));
            validate_non_negative_index("s", "n", n);
            s = std::vector<int>(n,int(0));
            vals_i__ = context__.vals_i("s");
            pos__ = 0;
            size_t s_limit_0__ = n;
            for (size_t i_0__ = 0; i_0__ < s_limit_0__; ++i_0__) {
                s[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 9;
            validate_non_negative_index("p_ids", "6", 6);
            context__.validate_dims("data initialization", "p_ids", "int", context__.to_vec(6));
            validate_non_negative_index("p_ids", "6", 6);
            p_ids = std::vector<int>(6,int(0));
            vals_i__ = context__.vals_i("p_ids");
            pos__ = 0;
            size_t p_ids_limit_0__ = 6;
            for (size_t i_0__ = 0; i_0__ < p_ids_limit_0__; ++i_0__) {
                p_ids[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 10;
            validate_non_negative_index("p_values", "12", 12);
            context__.validate_dims("data initialization", "p_values", "double", context__.to_vec(12));
            validate_non_negative_index("p_values", "12", 12);
            p_values = std::vector<double>(12,double(0));
            vals_r__ = context__.vals_r("p_values");
            pos__ = 0;
            size_t p_values_limit_0__ = 12;
            for (size_t i_0__ = 0; i_0__ < p_values_limit_0__; ++i_0__) {
                p_values[i_0__] = vals_r__[pos__++];
            }

            // validate, data variables
            current_statement_begin__ = 2;
            check_greater_or_equal(function__,"n",n,0);
            current_statement_begin__ = 3;
            check_greater_or_equal(function__,"m",m,0);
            current_statement_begin__ = 4;
            current_statement_begin__ = 5;
            current_statement_begin__ = 6;
            for (int k0__ = 0; k0__ < n; ++k0__) {
                check_greater_or_equal(function__,"s[k0__]",s[k0__],0);
            }
            current_statement_begin__ = 9;
            for (int k0__ = 0; k0__ < 6; ++k0__) {
                check_greater_or_equal(function__,"p_ids[k0__]",p_ids[k0__],0);
            }
            current_statement_begin__ = 10;
            for (int k0__ = 0; k0__ < 12; ++k0__) {
                check_greater_or_equal(function__,"p_values[k0__]",p_values[k0__],0);
            }
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 15;
            validate_non_negative_index("alpha", "m", m);
            num_params_r__ += m;
            current_statement_begin__ = 16;
            validate_non_negative_index("beta", "m", m);
            num_params_r__ += m;
            current_statement_begin__ = 17;
            validate_non_negative_index("sigma", "m", m);
            num_params_r__ += m;
            current_statement_begin__ = 20;
            ++num_params_r__;
            current_statement_begin__ = 21;
            ++num_params_r__;
            current_statement_begin__ = 22;
            ++num_params_r__;
            current_statement_begin__ = 23;
            ++num_params_r__;
            current_statement_begin__ = 24;
            ++num_params_r__;
            current_statement_begin__ = 25;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_linear() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("alpha")))
            throw std::runtime_error("variable alpha missing");
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        validate_non_negative_index("alpha", "m", m);
        context__.validate_dims("initialization", "alpha", "vector_d", context__.to_vec(m));
        vector_d alpha(static_cast<Eigen::VectorXd::Index>(m));
        for (int j1__ = 0U; j1__ < m; ++j1__)
            alpha(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_unconstrain(alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable alpha: ") + e.what());
        }

        if (!(context__.contains_r("beta")))
            throw std::runtime_error("variable beta missing");
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        validate_non_negative_index("beta", "m", m);
        context__.validate_dims("initialization", "beta", "vector_d", context__.to_vec(m));
        vector_d beta(static_cast<Eigen::VectorXd::Index>(m));
        for (int j1__ = 0U; j1__ < m; ++j1__)
            beta(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_unconstrain(beta);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable beta: ") + e.what());
        }

        if (!(context__.contains_r("sigma")))
            throw std::runtime_error("variable sigma missing");
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        validate_non_negative_index("sigma", "m", m);
        context__.validate_dims("initialization", "sigma", "vector_d", context__.to_vec(m));
        vector_d sigma(static_cast<Eigen::VectorXd::Index>(m));
        for (int j1__ = 0U; j1__ < m; ++j1__)
            sigma(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,sigma);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma: ") + e.what());
        }

        if (!(context__.contains_r("mu_a")))
            throw std::runtime_error("variable mu_a missing");
        vals_r__ = context__.vals_r("mu_a");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_a", "double", context__.to_vec());
        double mu_a(0);
        mu_a = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu_a);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_a: ") + e.what());
        }

        if (!(context__.contains_r("mu_b")))
            throw std::runtime_error("variable mu_b missing");
        vals_r__ = context__.vals_r("mu_b");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_b", "double", context__.to_vec());
        double mu_b(0);
        mu_b = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu_b);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_b: ") + e.what());
        }

        if (!(context__.contains_r("mu_s")))
            throw std::runtime_error("variable mu_s missing");
        vals_r__ = context__.vals_r("mu_s");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_s", "double", context__.to_vec());
        double mu_s(0);
        mu_s = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mu_s);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_s: ") + e.what());
        }

        if (!(context__.contains_r("sigma_a")))
            throw std::runtime_error("variable sigma_a missing");
        vals_r__ = context__.vals_r("sigma_a");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_a", "double", context__.to_vec());
        double sigma_a(0);
        sigma_a = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_a);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_a: ") + e.what());
        }

        if (!(context__.contains_r("sigma_b")))
            throw std::runtime_error("variable sigma_b missing");
        vals_r__ = context__.vals_r("sigma_b");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_b", "double", context__.to_vec());
        double sigma_b(0);
        sigma_b = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_b);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_b: ") + e.what());
        }

        if (!(context__.contains_r("sigma_s")))
            throw std::runtime_error("variable sigma_s missing");
        vals_r__ = context__.vals_r("sigma_s");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_s", "double", context__.to_vec());
        double sigma_s(0);
        sigma_s = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_s);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_s: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.vector_constrain(m,lp__);
            else
                alpha = in__.vector_constrain(m);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  beta;
            (void) beta;  // dummy to suppress unused var warning
            if (jacobian__)
                beta = in__.vector_constrain(m,lp__);
            else
                beta = in__.vector_constrain(m);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.vector_lb_constrain(0,m,lp__);
            else
                sigma = in__.vector_lb_constrain(0,m);

            local_scalar_t__ mu_a;
            (void) mu_a;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_a = in__.scalar_constrain(lp__);
            else
                mu_a = in__.scalar_constrain();

            local_scalar_t__ mu_b;
            (void) mu_b;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_b = in__.scalar_constrain(lp__);
            else
                mu_b = in__.scalar_constrain();

            local_scalar_t__ mu_s;
            (void) mu_s;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_s = in__.scalar_lb_constrain(0,lp__);
            else
                mu_s = in__.scalar_lb_constrain(0);

            local_scalar_t__ sigma_a;
            (void) sigma_a;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_a = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_a = in__.scalar_lb_constrain(0);

            local_scalar_t__ sigma_b;
            (void) sigma_b;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_b = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_b = in__.scalar_lb_constrain(0);

            local_scalar_t__ sigma_s;
            (void) sigma_s;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_s = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_s = in__.scalar_lb_constrain(0);


            // transformed parameters



            // validate transformed parameters

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // model body
            {
            current_statement_begin__ = 31;
            int id(0);
            (void) id;  // dummy to suppress unused var warning

            stan::math::fill(id, std::numeric_limits<int>::min());
            stan::math::assign(id,1);


            current_statement_begin__ = 32;
            if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),1))) {

                current_statement_begin__ = 33;
                lp_accum__.add(uniform_log<propto__>(mu_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),2))) {

                current_statement_begin__ = 35;
                lp_accum__.add(normal_log<propto__>(mu_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),3))) {

                current_statement_begin__ = 37;
                lp_accum__.add(gamma_log<propto__>(mu_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),4))) {

                current_statement_begin__ = 39;
                lp_accum__.add(beta_log<propto__>(mu_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            }
            current_statement_begin__ = 42;
            stan::math::assign(id, 2);
            current_statement_begin__ = 43;
            if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),1))) {

                current_statement_begin__ = 44;
                lp_accum__.add(uniform_log<propto__>(sigma_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),2))) {

                current_statement_begin__ = 46;
                lp_accum__.add(normal_log<propto__>(sigma_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),3))) {

                current_statement_begin__ = 48;
                lp_accum__.add(gamma_log<propto__>(sigma_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),4))) {

                current_statement_begin__ = 50;
                lp_accum__.add(beta_log<propto__>(sigma_a, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            }
            current_statement_begin__ = 54;
            stan::math::assign(id, 3);
            current_statement_begin__ = 55;
            if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),1))) {

                current_statement_begin__ = 56;
                lp_accum__.add(uniform_log<propto__>(mu_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),2))) {

                current_statement_begin__ = 58;
                lp_accum__.add(normal_log<propto__>(mu_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),3))) {

                current_statement_begin__ = 60;
                lp_accum__.add(gamma_log<propto__>(mu_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),4))) {

                current_statement_begin__ = 62;
                lp_accum__.add(beta_log<propto__>(mu_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            }
            current_statement_begin__ = 65;
            stan::math::assign(id, 4);
            current_statement_begin__ = 66;
            if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),1))) {

                current_statement_begin__ = 67;
                lp_accum__.add(uniform_log<propto__>(sigma_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),2))) {

                current_statement_begin__ = 69;
                lp_accum__.add(normal_log<propto__>(sigma_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),3))) {

                current_statement_begin__ = 71;
                lp_accum__.add(gamma_log<propto__>(sigma_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),4))) {

                current_statement_begin__ = 73;
                lp_accum__.add(beta_log<propto__>(sigma_b, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            }
            current_statement_begin__ = 77;
            stan::math::assign(id, 5);
            current_statement_begin__ = 78;
            if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),1))) {

                current_statement_begin__ = 79;
                lp_accum__.add(uniform_log<propto__>(mu_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),2))) {

                current_statement_begin__ = 81;
                lp_accum__.add(normal_log<propto__>(mu_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),3))) {

                current_statement_begin__ = 83;
                lp_accum__.add(gamma_log<propto__>(mu_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),4))) {

                current_statement_begin__ = 85;
                lp_accum__.add(beta_log<propto__>(mu_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            }
            current_statement_begin__ = 88;
            stan::math::assign(id, 6);
            current_statement_begin__ = 89;
            if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),1))) {

                current_statement_begin__ = 90;
                lp_accum__.add(uniform_log<propto__>(sigma_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),2))) {

                current_statement_begin__ = 92;
                lp_accum__.add(normal_log<propto__>(sigma_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),3))) {

                current_statement_begin__ = 94;
                lp_accum__.add(gamma_log<propto__>(sigma_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            } else if (as_bool(logical_eq(get_base1(p_ids,id,"p_ids",1),4))) {

                current_statement_begin__ = 96;
                lp_accum__.add(beta_log<propto__>(sigma_s, get_base1(p_values,((id * 2) - 1),"p_values",1), get_base1(p_values,(id * 2),"p_values",1)));
            }
            current_statement_begin__ = 99;
            lp_accum__.add(normal_log<propto__>(alpha, mu_a, sigma_a));
            current_statement_begin__ = 100;
            lp_accum__.add(normal_log<propto__>(beta, mu_b, sigma_b));
            current_statement_begin__ = 101;
            lp_accum__.add(normal_log<propto__>(sigma, mu_s, sigma_s));
            current_statement_begin__ = 103;
            for (int i = 1; i <= n; ++i) {
                current_statement_begin__ = 104;
                lp_accum__.add(normal_log<propto__>(get_base1(y,i,"y",1), (get_base1(alpha,get_base1(s,i,"s",1),"alpha",1) + (get_base1(beta,get_base1(s,i,"s",1),"beta",1) * get_base1(x,i,"x",1))), get_base1(sigma,get_base1(s,i,"s",1),"sigma",1)));
            }
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("alpha");
        names__.push_back("beta");
        names__.push_back("sigma");
        names__.push_back("mu_a");
        names__.push_back("mu_b");
        names__.push_back("mu_s");
        names__.push_back("sigma_a");
        names__.push_back("sigma_b");
        names__.push_back("sigma_s");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(m);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(m);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(m);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_linear_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector_d alpha = in__.vector_constrain(m);
        vector_d beta = in__.vector_constrain(m);
        vector_d sigma = in__.vector_lb_constrain(0,m);
        double mu_a = in__.scalar_constrain();
        double mu_b = in__.scalar_constrain();
        double mu_s = in__.scalar_lb_constrain(0);
        double sigma_a = in__.scalar_lb_constrain(0);
        double sigma_b = in__.scalar_lb_constrain(0);
        double sigma_s = in__.scalar_lb_constrain(0);
            for (int k_0__ = 0; k_0__ < m; ++k_0__) {
            vars__.push_back(alpha[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < m; ++k_0__) {
            vars__.push_back(beta[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < m; ++k_0__) {
            vars__.push_back(sigma[k_0__]);
            }
        vars__.push_back(mu_a);
        vars__.push_back(mu_b);
        vars__.push_back(mu_s);
        vars__.push_back(sigma_a);
        vars__.push_back(sigma_b);
        vars__.push_back(sigma_s);

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {



            // validate transformed parameters

            // write transformed parameters
            if (include_tparams__) {
            }
            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_linear";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_b";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_s";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_b";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_s";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_b";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_s";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_b";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_s";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }

}; // model

}

typedef model_linear_namespace::model_linear stan_model;


#endif
