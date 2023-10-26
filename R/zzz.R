# files and functions that should be loaded at last when calling library(LambertW)

#.onLoad <- function (libname, pkgname) {
#  library.dynam.unload("LambertW", file.path(libname, pkgname))
#}

.onAttach <- function(libname, pkgname){
  welcome.msg <- 
    paste0("This is 'LambertW' v", utils::packageVersion("LambertW"), 
           '. See NEWS and citation("LambertW").\n\n')
  welcome.msg <- paste0(welcome.msg, 
                        "R:      https://github.com/gmgeorg/LambertW\n")
  welcome.msg <- paste0(welcome.msg, "Python: https://github.com/gmgeorg/pylambertw\n")
  welcome.msg <- paste0(welcome.msg, 
                        "---------------------------------------------")
  packageStartupMessage(welcome.msg, domain = NULL, 
                        appendLF = TRUE)
}

#.onUnload <- function(libpath) {
#  library.dynam.unload("LambertW", libpath)
#}
