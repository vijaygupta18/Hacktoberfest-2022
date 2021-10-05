import Navbar from './components/Navbar';
import './App.css';
import {useEffect,useState} from 'react';
import { DragDropContext, Draggable, Droppable } from 'react-beautiful-dnd';


function RepoList(props) {
  const repos = props.repos;
  const listItems = repos.map((value,index) =>

      <Draggable  key={value.id} draggableId={JSON.stringify(value.id)} index={index}>

        {(provided)=>(
            <figure className="col-sm-8 m-4 snip1540" id="snip1540" {...provided.draggableProps} {...provided.dragHandleProps} ref={provided.innerRef} >

            <div className="profile-image">
              <a href={value.owner.html_url}>
                  <img src={value.owner.avatar_url} alt="profile-sample9" />
              </a>
              
              <div className="icons" style={{color:"white", fontSize: "2rem"}}>
                <a href={value.html_url}  style={{color:"white", fontSize: "2rem"}}>
                  <i className="fa fa-github" style={{fontSize: "2rem"}}></i>
                </a>
              </div>
            
            </div>
            <figcaption>

              <h3>{value.name}</h3>
              <h4>By {value.owner.login}</h4>
              <p>{value.description}</p>

            </figcaption>

            {provided.placeholder}

          </figure>
        )}
      </Draggable>
    
  );
  return (
    <div className="row">
      {listItems}
    </div>
  );
}


function App() {

  const [data, setData] = useState([]);
  const [search, setSearch] = useState('')
  const [characters, updateCharacters] = useState(data);


  useEffect(() => {
    var myHeaders = new Headers();
    myHeaders.append("Content-Type", "application/json");

    var requestOptions = {
      method: 'GET',
      headers: myHeaders,
      redirect: 'follow',
      type: 'no-cors'
    };

    fetch("https://api.github.com/repositories", requestOptions)
      .then(response => response.json())
      .then(result => {
         setData(result);
         updateCharacters(result);
        })
      .catch(error => console.log('error', error));

  },[]);


  const filterPosts = (data, query) => {
    
    return data.filter((repo) => {
        const postName = repo.name.toLowerCase();
        return postName.includes(query);
    });

};

  function handleChange(e){
    setSearch(e.target.value); 
   
    const list = filterPosts(data, e.target.value);
    if(list.length > 10){
      const tempList = list.slice(0,10);
      updateCharacters(tempList);
    }else{
      updateCharacters(list);
    }
  }

  function handleDrag(result) {

    if (!result.destination) return;

    const items = Array.from(characters);
    const [reorderedItem] = items.splice(result.source.index, 1);
    items.splice(result.destination.index, 0, reorderedItem);

    updateCharacters(items);

  }


  return (
    <div className="App">
      <Navbar/>

      <div className="container mt-5">

        <form class="d-flex ms-5 me-4 ms-5 search">

              <input class="form-control me-2" type="search"  aria-label="Search" 
              placeholder="Search name" 
              value={search}
              onChange={(e)=>{handleChange(e)}}/>
              
              <button class="btn btn-outline-success" type="submit">Search</button>
        </form>

            <div className="container boxes" style={{width:"80%", alignItems:"center"}}>

              <DragDropContext onDragEnd={handleDrag}>

                <Droppable droppableId="characters">

                  {(provided)=>(
                      <div id="characters" className="row m-5 mt-5"  
                      style={{alignItems:"center"}} 
                      {...provided.droppableProps} 
                      ref={provided.innerRef}>
                      
                      <RepoList repos={characters}/>

                      {provided.placeholder}

                    </div>
                  )}

                  
                </Droppable>

              </DragDropContext>
              
              </div>
              
          </div>
      </div>
  );
}

export default App;
