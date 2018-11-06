data {
  int<lower=0> n; // total number of measurements
  int<lower=0> m; // number of subjects
  vector<lower=0>[n] rt; // reaction times
  int<lower=0,upper=1> r[n]; // results - success or fail
  int<lower=0> s[n]; // id of the subject
}

parameters {
  // reaction times
  vector<lower=0>[m] mu;
  vector<lower=0>[m] sigma;
  vector<lower=0>[m] lambda;
  real mu_m;
  real mu_l;
  real mu_s;
  real<lower=0> ss_m;
  real<lower=0> ss_l;
  real<lower=0> ss_s;

  // success probability
  vector<lower=0,upper=1>[m] p;
  real<lower=0> a;
  real<lower=0> b;
}

model {
  mu ~ normal(mu_m, ss_m);
  sigma ~ normal(mu_s, ss_s);
  lambda ~ normal(mu_l, ss_l);
  p ~ beta(a, b);

  // iterate over all measurements
  for (i in 1:n) {
    rt[i] ~ exp_mod_normal(mu[s[i]], sigma[s[i]], lambda[s[i]]);
    r[i] ~ bernoulli(p[s[i]]);
  }
}
