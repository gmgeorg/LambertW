# files and functions that should be loaded at last when calling library(LambertW)

#.onLoad <- function (libname, pkgname) {
#  library.dynam.unload("LambertW", file.path(libname, pkgname))
#}

.onAttach <- function(libname, pkgname){
  welcome.msg <- 
    paste0("This is 'LambertW' version ", utils::packageVersion("LambertW"), 
           '. See the NEWS file and citation("LambertW").\n')
  packageStartupMessage(welcome.msg, domain = NULL, 
                        appendLF = TRUE)
}

#.onUnload <- function(libpath) {
#  library.dynam.unload("LambertW", libpath)
#}
