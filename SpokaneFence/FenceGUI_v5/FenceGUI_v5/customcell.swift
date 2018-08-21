//
//  estimate.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/9/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class customcell: UITableViewCell {
    
    var cus: Customer?
    var name: String?
    var address: String?
    var id: Int?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
}

class estimatecell: UITableViewCell {
    
    var est: Estimate?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
        
        // Configure the view for the selected state
    }
    
}

class linecell: UITableViewCell {
    
}

class gatecell: UITableViewCell {
    
    
}

class extracell: UITableViewCell {
    
}
