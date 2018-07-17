//
//  estimate.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/9/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class customcell: UITableViewCell {
    
    var est: Estimate?
    var name: String?
    var address: String?
    var date: Date?
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
