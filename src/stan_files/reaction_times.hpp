/*
    EasyBayes is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    EasyBayes is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with EasyBayes.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_reaction_times_namespace {

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
    reader.add_event(0, 0, "start", "model_reaction_times");
    reader.add_event(40, 38, "end", "model_reaction_times");
    return reader;
}

#include <meta_header.hpp>
 class model_reaction_times : public prob_grad {
private:
    int n;
    int m;
    vector_d rt;
    vector<int> r;
    vector<int> s;
public:
    model_reaction_times(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_reaction_times(stan::io::var_context& context__,
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

        static const char* function__ = "model_reaction_times_namespace::model_reaction_times";
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
            validate_non_negative_index("rt", "n", n);
            context__.validate_dims("data initialization", "rt", "vector_d", context__.to_vec(n));
            validate_non_negative_index("rt", "n", n);
            rt = vector_d(static_cast<Eigen::VectorXd::Index>(n));
            vals_r__ = context__.vals_r("rt");
            pos__ = 0;
            size_t rt_i_vec_lim__ = n;
            for (size_t i_vec__ = 0; i_vec__ < rt_i_vec_lim__; ++i_vec__) {
                rt[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 5;
            validate_non_negative_index("r", "n", n);
            context__.validate_dims("data initialization", "r", "int", context__.to_vec(n));
            validate_non_negative_index("r", "n", n);
            r = std::vector<int>(n,int(0));
            vals_i__ = context__.vals_i("r");
            pos__ = 0;
            size_t r_limit_0__ = n;
            for (size_t i_0__ = 0; i_0__ < r_limit_0__; ++i_0__) {
                r[i_0__] = vals_i__[pos__++];
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

            // validate, data variables
            current_statement_begin__ = 2;
            check_greater_or_equal(function__,"n",n,0);
            current_statement_begin__ = 3;
            check_greater_or_equal(function__,"m",m,0);
            current_statement_begin__ = 4;
            check_greater_or_equal(function__,"rt",rt,0);
            current_statement_begin__ = 5;
            for (int k0__ = 0; k0__ < n; ++k0__) {
                check_greater_or_equal(function__,"r[k0__]",r[k0__],0);
                check_less_or_equal(function__,"r[k0__]",r[k0__],1);
            }
            current_statement_begin__ = 6;
            for (int k0__ = 0; k0__ < n; ++k0__) {
                check_greater_or_equal(function__,"s[k0__]",s[k0__],0);
            }
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 11;
            validate_non_negative_index("mu", "m", m);
            num_params_r__ += m;
            current_statement_begin__ = 12;
            validate_non_negative_index("sigma", "m", m);
            num_params_r__ += m;
            current_statement_begin__ = 13;
            validate_non_negative_index("lambda", "m", m);
            num_params_r__ += m;
            current_statement_begin__ = 14;
            ++num_params_r__;
            current_statement_begin__ = 15;
            ++num_params_r__;
            current_statement_begin__ = 16;
            ++num_params_r__;
            current_statement_begin__ = 17;
            ++num_params_r__;
            current_statement_begin__ = 18;
            ++num_params_r__;
            current_statement_begin__ = 19;
            ++num_params_r__;
            current_statement_begin__ = 22;
            validate_non_negative_index("p", "m", m);
            num_params_r__ += m;
            current_statement_begin__ = 23;
            ++num_params_r__;
            current_statement_begin__ = 24;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_reaction_times() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("mu")))
            throw std::runtime_error("variable mu missing");
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        validate_non_negative_index("mu", "m", m);
        context__.validate_dims("initialization", "mu", "vector_d", context__.to_vec(m));
        vector_d mu(static_cast<Eigen::VectorXd::Index>(m));
        for (int j1__ = 0U; j1__ < m; ++j1__)
            mu(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,mu);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu: ") + e.what());
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

        if (!(context__.contains_r("lambda")))
            throw std::runtime_error("variable lambda missing");
        vals_r__ = context__.vals_r("lambda");
        pos__ = 0U;
        validate_non_negative_index("lambda", "m", m);
        context__.validate_dims("initialization", "lambda", "vector_d", context__.to_vec(m));
        vector_d lambda(static_cast<Eigen::VectorXd::Index>(m));
        for (int j1__ = 0U; j1__ < m; ++j1__)
            lambda(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,lambda);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable lambda: ") + e.what());
        }

        if (!(context__.contains_r("mu_m")))
            throw std::runtime_error("variable mu_m missing");
        vals_r__ = context__.vals_r("mu_m");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_m", "double", context__.to_vec());
        double mu_m(0);
        mu_m = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu_m);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_m: ") + e.what());
        }

        if (!(context__.contains_r("mu_l")))
            throw std::runtime_error("variable mu_l missing");
        vals_r__ = context__.vals_r("mu_l");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_l", "double", context__.to_vec());
        double mu_l(0);
        mu_l = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu_l);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_l: ") + e.what());
        }

        if (!(context__.contains_r("mu_s")))
            throw std::runtime_error("variable mu_s missing");
        vals_r__ = context__.vals_r("mu_s");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu_s", "double", context__.to_vec());
        double mu_s(0);
        mu_s = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu_s);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu_s: ") + e.what());
        }

        if (!(context__.contains_r("ss_m")))
            throw std::runtime_error("variable ss_m missing");
        vals_r__ = context__.vals_r("ss_m");
        pos__ = 0U;
        context__.validate_dims("initialization", "ss_m", "double", context__.to_vec());
        double ss_m(0);
        ss_m = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,ss_m);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable ss_m: ") + e.what());
        }

        if (!(context__.contains_r("ss_l")))
            throw std::runtime_error("variable ss_l missing");
        vals_r__ = context__.vals_r("ss_l");
        pos__ = 0U;
        context__.validate_dims("initialization", "ss_l", "double", context__.to_vec());
        double ss_l(0);
        ss_l = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,ss_l);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable ss_l: ") + e.what());
        }

        if (!(context__.contains_r("ss_s")))
            throw std::runtime_error("variable ss_s missing");
        vals_r__ = context__.vals_r("ss_s");
        pos__ = 0U;
        context__.validate_dims("initialization", "ss_s", "double", context__.to_vec());
        double ss_s(0);
        ss_s = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,ss_s);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable ss_s: ") + e.what());
        }

        if (!(context__.contains_r("p")))
            throw std::runtime_error("variable p missing");
        vals_r__ = context__.vals_r("p");
        pos__ = 0U;
        validate_non_negative_index("p", "m", m);
        context__.validate_dims("initialization", "p", "vector_d", context__.to_vec(m));
        vector_d p(static_cast<Eigen::VectorXd::Index>(m));
        for (int j1__ = 0U; j1__ < m; ++j1__)
            p(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lub_unconstrain(0,1,p);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable p: ") + e.what());
        }

        if (!(context__.contains_r("a")))
            throw std::runtime_error("variable a missing");
        vals_r__ = context__.vals_r("a");
        pos__ = 0U;
        context__.validate_dims("initialization", "a", "double", context__.to_vec());
        double a(0);
        a = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,a);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable a: ") + e.what());
        }

        if (!(context__.contains_r("b")))
            throw std::runtime_error("variable b missing");
        vals_r__ = context__.vals_r("b");
        pos__ = 0U;
        context__.validate_dims("initialization", "b", "double", context__.to_vec());
        double b(0);
        b = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,b);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable b: ") + e.what());
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

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  mu;
            (void) mu;  // dummy to suppress unused var warning
            if (jacobian__)
                mu = in__.vector_lb_constrain(0,m,lp__);
            else
                mu = in__.vector_lb_constrain(0,m);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.vector_lb_constrain(0,m,lp__);
            else
                sigma = in__.vector_lb_constrain(0,m);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  lambda;
            (void) lambda;  // dummy to suppress unused var warning
            if (jacobian__)
                lambda = in__.vector_lb_constrain(0,m,lp__);
            else
                lambda = in__.vector_lb_constrain(0,m);

            local_scalar_t__ mu_m;
            (void) mu_m;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_m = in__.scalar_constrain(lp__);
            else
                mu_m = in__.scalar_constrain();

            local_scalar_t__ mu_l;
            (void) mu_l;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_l = in__.scalar_constrain(lp__);
            else
                mu_l = in__.scalar_constrain();

            local_scalar_t__ mu_s;
            (void) mu_s;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_s = in__.scalar_constrain(lp__);
            else
                mu_s = in__.scalar_constrain();

            local_scalar_t__ ss_m;
            (void) ss_m;  // dummy to suppress unused var warning
            if (jacobian__)
                ss_m = in__.scalar_lb_constrain(0,lp__);
            else
                ss_m = in__.scalar_lb_constrain(0);

            local_scalar_t__ ss_l;
            (void) ss_l;  // dummy to suppress unused var warning
            if (jacobian__)
                ss_l = in__.scalar_lb_constrain(0,lp__);
            else
                ss_l = in__.scalar_lb_constrain(0);

            local_scalar_t__ ss_s;
            (void) ss_s;  // dummy to suppress unused var warning
            if (jacobian__)
                ss_s = in__.scalar_lb_constrain(0,lp__);
            else
                ss_s = in__.scalar_lb_constrain(0);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  p;
            (void) p;  // dummy to suppress unused var warning
            if (jacobian__)
                p = in__.vector_lub_constrain(0,1,m,lp__);
            else
                p = in__.vector_lub_constrain(0,1,m);

            local_scalar_t__ a;
            (void) a;  // dummy to suppress unused var warning
            if (jacobian__)
                a = in__.scalar_lb_constrain(0,lp__);
            else
                a = in__.scalar_lb_constrain(0);

            local_scalar_t__ b;
            (void) b;  // dummy to suppress unused var warning
            if (jacobian__)
                b = in__.scalar_lb_constrain(0,lp__);
            else
                b = in__.scalar_lb_constrain(0);


            // transformed parameters



            // validate transformed parameters

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // model body

            current_statement_begin__ = 28;
            lp_accum__.add(normal_log<propto__>(mu, mu_m, ss_m));
            current_statement_begin__ = 29;
            lp_accum__.add(normal_log<propto__>(sigma, mu_s, ss_s));
            current_statement_begin__ = 30;
            lp_accum__.add(normal_log<propto__>(lambda, mu_l, ss_l));
            current_statement_begin__ = 31;
            lp_accum__.add(beta_log<propto__>(p, a, b));
            current_statement_begin__ = 34;
            for (int i = 1; i <= n; ++i) {

                current_statement_begin__ = 35;
                lp_accum__.add(exp_mod_normal_log<propto__>(get_base1(rt,i,"rt",1), get_base1(mu,get_base1(s,i,"s",1),"mu",1), get_base1(sigma,get_base1(s,i,"s",1),"sigma",1), get_base1(lambda,get_base1(s,i,"s",1),"lambda",1)));
                current_statement_begin__ = 36;
                lp_accum__.add(bernoulli_log<propto__>(get_base1(r,i,"r",1), get_base1(p,get_base1(s,i,"s",1),"p",1)));
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
        names__.push_back("mu");
        names__.push_back("sigma");
        names__.push_back("lambda");
        names__.push_back("mu_m");
        names__.push_back("mu_l");
        names__.push_back("mu_s");
        names__.push_back("ss_m");
        names__.push_back("ss_l");
        names__.push_back("ss_s");
        names__.push_back("p");
        names__.push_back("a");
        names__.push_back("b");
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
        dims__.resize(0);
        dims__.push_back(m);
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
        static const char* function__ = "model_reaction_times_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector_d mu = in__.vector_lb_constrain(0,m);
        vector_d sigma = in__.vector_lb_constrain(0,m);
        vector_d lambda = in__.vector_lb_constrain(0,m);
        double mu_m = in__.scalar_constrain();
        double mu_l = in__.scalar_constrain();
        double mu_s = in__.scalar_constrain();
        double ss_m = in__.scalar_lb_constrain(0);
        double ss_l = in__.scalar_lb_constrain(0);
        double ss_s = in__.scalar_lb_constrain(0);
        vector_d p = in__.vector_lub_constrain(0,1,m);
        double a = in__.scalar_lb_constrain(0);
        double b = in__.scalar_lb_constrain(0);
            for (int k_0__ = 0; k_0__ < m; ++k_0__) {
            vars__.push_back(mu[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < m; ++k_0__) {
            vars__.push_back(sigma[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < m; ++k_0__) {
            vars__.push_back(lambda[k_0__]);
            }
        vars__.push_back(mu_m);
        vars__.push_back(mu_l);
        vars__.push_back(mu_s);
        vars__.push_back(ss_m);
        vars__.push_back(ss_l);
        vars__.push_back(ss_s);
            for (int k_0__ = 0; k_0__ < m; ++k_0__) {
            vars__.push_back(p[k_0__]);
            }
        vars__.push_back(a);
        vars__.push_back(b);

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
        return "model_reaction_times";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "lambda" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_m";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_l";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_s";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ss_m";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ss_l";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ss_s";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "p" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "b";
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
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "lambda" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_m";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_l";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_s";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ss_m";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ss_l";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ss_s";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= m; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "p" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "b";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }

}; // model

}

typedef model_reaction_times_namespace::model_reaction_times stan_model;


#endif
