% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/reaction_time_class.R
\name{plot_distributions_difference,reaction_time_class-method}
\alias{plot_distributions_difference,reaction_time_class-method}
\alias{plot_distributions_difference_reaction_time}
\title{plot_distributions_difference}
\usage{
\S4method{plot_distributions_difference}{reaction_time_class}(object, ...)
}
\arguments{
\item{object}{reaction_time_class object.}

\item{...}{fit2 - a second reaction_time_class object, fits - a list of reaction_time_class objects, rope - region of practical equivalence, bins - number of bins in the histogram.}
}
\value{
A ggplot visualization or an error if something went wrong.
}
\description{
\code{plot_distributions_difference} a visualization of the difference between the distribution of the first group and the second group or between multiple groups.
}
\examples{
# to use the function you first have to prepare the data and fit the model
# see class documentation for an example of the whole process
# along with an example of how to use this function
?reaction_time_class

}
