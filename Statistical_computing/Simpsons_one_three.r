# In simpson's 1/3 the number of observations should always be odd
# Formula is
# Integration = (h/3)(((y₀ + yₙ) * 4(y₁ + y₂ + y₃ + ...) * 2(y₂ + y₄ + y₆ + ...))

x <- c(1.4,1.6,1.8,2,2.2)
y <- c(4.0552,4.953,6.0436,7.3891,9.025)
# To find length
n <- length(y)
# Find h i.e. difference between term
h <- x[2] - x[1]
# Get sum of all the odd terms
coeffFour <- 0
# Get sum of all even terms starting from 2nd position
coeffTwo <- 0
for(i in 2:n){
    if(as.integer(i %% 2 == 0)){
        coeffFour = coeffFour + y[i];
    }else{
        coeffTwo = coeffTwo + y[i];
    }
    i = i + 1;
}
# Exclude the last term from the sum of all odd term observations
coeffTwo = coeffTwo - y[n]
# Apply the formula
S <- (h / 3) * (y[1] + y[n] + (4 * coeffFour) + (2 * coeffTwo))
print(S)