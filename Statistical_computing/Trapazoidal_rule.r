# Formula
# Integration = (h / 2) * ((y₀ + yₙ₊₁) + (2 * (y₁ + y₂ + y₃ + ... + yₙ)))
x <- c(-4,-3,-2,-1,0,1,2)
y <- c(0,4,5,3,10,11,2)
n <- length(y)
h <- x[2] - x[1]
S <- 0
for(i in 2:(n-1)){
    S <- S + y[i]
}
print(S)
S <- (h / 2) * (y[1] + y[n] + (2 * S))
print(S)