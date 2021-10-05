import React from 'react'

function Navbar() {
    return (
        <div>
          <nav className="navbar navbar-expand-lg navbar-dark ">
            <div className="container-fluid ms-5">
             <a className="navbar-brand" href="https://github.com/" style={{fontSize:"3rem"}}>
                  GitHub 
                  <i  className="fa fa-github"></i>
               </a>
            </div>
          </nav>
        </div>
    )
}

export default Navbar
