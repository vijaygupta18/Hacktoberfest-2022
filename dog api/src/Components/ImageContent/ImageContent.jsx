import React from 'react'
import './ImageContent.css'
const ImageContent = ({src}) => {
    return (
        <div className="image_holder">
            <img src={src} alt="Dog" />
        </div>
    )
}

export default ImageContent
