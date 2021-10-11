import React from 'react'

function card({repos}) {
  console.log("repos",repos);
  //const data = JSON.parse(repos);
  
  //const data = JSON.parse(repos[0]);
  //console.log("data",data);
  const display = repos.map(ele=>{
            console.log("ele",ele);
              ele.map(e=>{
                return(
                  <h1>hello</h1>
              )})
    })
  return (
    <div className="col">
      <h1>displ</h1>
     {
       display
     }
    </div>
  )
}

export default card
